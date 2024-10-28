#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include "structures.h"

int register_user(Node* nodes, User* users, int* user_count, 
                 const char* username, const char* dob, const char* password);
char* login(User* users, int user_count, const char* username, const char* password);
int verify_token(User* users, int user_count, const char* username, const char* token);
void save_users_to_file(User* users, int user_count, const char* filename);
int load_users_from_file(User* users, int* user_count, const char* filename);

#endif