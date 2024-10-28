#ifndef TERMINAL_UI_H
#define TERMINAL_UI_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Color codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

// Background colors
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

void clear_screen();
void show_loading(const char* message);
void show_success(const char* message);
void show_error(const char* message);
void show_header();
void show_menu();
void animate_blockchain_creation();

#endif