#include <string.h>
#include <stdio.h>
#include "user_management.h"
#include "password_security.h"
#include "blockchain.h"
#include "crypto_utils.h"

int register_user(Node* nodes, User* users, int* user_count, 
                 const char* username, const char* dob, const char* password) {
    if(*user_count >= MAX_USERS) {
        return 0;
    }
    
    for(int i = 0; i < *user_count; i++) {
        if(strcmp(users[i].username, username) == 0) {
            return 0;
        }
    }
    
    User new_user;
    strncpy(new_user.username, username, sizeof(new_user.username) - 1);
    strncpy(new_user.dob, dob, sizeof(new_user.dob) - 1);
    
    unsigned char salt[SALT_LENGTH];
    generate_salt(salt);
    hash_password_with_salt(password, salt, &new_user.password_hash);
    
    generate_token(new_user.current_token);
    
    users[*user_count] = new_user;
    
    if(!add_block(nodes, &new_user, *user_count)) {
        return 0;
    }
    
    (*user_count)++;
    return 1;
}

char* login(User* users, int user_count, const char* username, const char* password) {
    for(int i = 0; i < user_count; i++) {
        if(strcmp(users[i].username, username) == 0) {
            if(verify_password(password, &users[i].password_hash)) {
                generate_token(users[i].current_token);
                return users[i].current_token;
            }
            break;
        }
    }
    return NULL;
}

int verify_token(User* users, int user_count, const char* username, const char* token) {
    for(int i = 0; i < user_count; i++) {
        if(strcmp(users[i].username, username) == 0) {
            return strcmp(users[i].current_token, token) == 0;
        }
    }
    return 0;
}

void save_users_to_file(User* users, int user_count, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if(file == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        return;
    }
    
    fwrite(&user_count, sizeof(int), 1, file);
    fwrite(users, sizeof(User), user_count, file);
    fclose(file);
}

int load_users_from_file(User* users, int* user_count, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if(file == NULL) {
        return 0;
    }
    
    fread(user_count, sizeof(int), 1, file);
    fread(users, sizeof(User), *user_count, file);
    fclose(file);
    return 1;
}