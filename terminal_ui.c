#include "terminal_ui.h"
#include <stdio.h>
#include <unistd.h>

void clear_screen() {
    printf("\033[2J\033[H");
}

void show_loading(const char* message) {
    printf("%s%s", CYAN, message);
    for(int i = 0; i < 3; i++) {
        fflush(stdout);
        printf(".");
        usleep(300000);  // 300ms delay
    }
    printf("%s\n", RESET);
}

void show_success(const char* message) {
    printf("%s%s✓ %s%s\n", BOLD, GREEN, message, RESET);
}

void show_error(const char* message) {
    printf("%s%s✗ %s%s\n", BOLD, RED, message, RESET);
}

void show_header() {
    clear_screen();
    printf("%s%s", BOLD, BLUE);
    printf("╔═══════════════════════════════════════╗\n");
    printf("║      BLOCKCHAIN LOGIN SYSTEM          ║\n");
    printf("╚═══════════════════════════════════════╝%s\n\n", RESET);
}

void show_menu() {
    printf("\n%s%sAvailable Options:%s\n", BOLD, YELLOW, RESET);
    printf("%s1%s. Register new user\n", CYAN, WHITE);
    printf("%s2%s. Login\n", CYAN, WHITE);
    printf("%s3%s. Verify token\n", CYAN, WHITE);
    printf("%s4%s. Exit\n\n", CYAN, WHITE);
    printf("%sChoose an option: %s", GREEN, RESET);
}

void animate_blockchain_creation() {
    printf("\n%sCreating blockchain structure:", YELLOW);
    for(int i = 0; i < 10; i++) {
        printf("%s ⬡", CYAN);
        fflush(stdout);
        usleep(200000);
    }
    printf("%s ✓%s\n", GREEN, RESET);
}