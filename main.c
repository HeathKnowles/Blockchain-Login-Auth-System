#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
#include "blockchain.h"
#include "user_management.h"
#include "password_security.h"
#include "terminal_ui.h"

#define USER_FILE "users.dat"

Node nodes[MAX_NODES];
User users[MAX_USERS];
int user_count = 0;

void register_new_user() {
    char username[50];
    char dob[11];
    char password[100];
    
    printf("\n%s=== User Registration ===%s\n", BOLD, RESET);
    printf("%sEnter username: %s", CYAN, RESET);
    scanf("%49s", username);
    printf("%sEnter date of birth (YYYY-MM-DD): %s", CYAN, RESET);
    scanf("%10s", dob);
    printf("%sEnter password: %s", CYAN, RESET);
    scanf("%99s", password);
    
    show_loading("Processing registration");
    
    if(register_user(nodes, users, &user_count, username, dob, password)) {
        show_success("User registered successfully!");
        save_users_to_file(users, user_count, USER_FILE);
    } else {
        show_error("Registration failed.");
    }
}

void perform_login() {
    char username[50];
    char password[100];
    
    printf("\n%s=== User Login ===%s\n", BOLD, RESET);
    printf("%sEnter username: %s", CYAN, RESET);
    scanf("%49s", username);
    printf("%sEnter password: %s", CYAN, RESET);
    scanf("%99s", password);
    
    show_loading("Authenticating");
    
    char* token = login(users, user_count, username, password);
    if(token) {
        show_success("Login successful!");
        printf("%sYour token is: %s%s%s\n", 
               YELLOW, BOLD, token, RESET);
        save_users_to_file(users, user_count, USER_FILE);
    } else {
        show_error("Login failed.");
    }
}

void verify_user_token() {
    char username[50];
    char token[TOKEN_LENGTH + 1];
    
    printf("\n%s=== Token Verification ===%s\n", BOLD, RESET);
    printf("%sEnter username: %s", CYAN, RESET);
    scanf("%49s", username);
    printf("%sEnter token: %s", CYAN, RESET);
    scanf("%6s", token);
    
    show_loading("Verifying token");
    
    if(verify_token(users, user_count, username, token)) {
        show_success("Token verified successfully!");
    } else {
        show_error("Token verification failed.");
    }
}

int main() {
    srand(time(NULL));
    
    show_header();
    animate_blockchain_creation();
    
    // Load existing users
    if(load_users_from_file(users, &user_count, USER_FILE)) {
        printf("%sLoaded %d existing users.%s\n", 
               GREEN, user_count, RESET);
    }
    
    int choice;
    do {
        show_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                register_new_user();
                break;
            case 2:
                perform_login();
                break;
            case 3:
                verify_user_token();
                break;
            case 4:
                printf("\n%s%sGoodbye!%s\n", BOLD, YELLOW, RESET);
                break;
            default:
                show_error("Invalid option.");
        }
    } while(choice != 4);
    
    return 0;
}