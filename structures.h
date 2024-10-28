#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <time.h>
#include "password_security.h"
#include <openssl/sha.h>

#define MAX_NODES 100
#define MAX_USERS 1000
#define TOKEN_LENGTH 6

typedef struct {
    char username[50];
    char dob[11];  // Format: YYYY-MM-DD
    PasswordHash password_hash;
    char current_token[TOKEN_LENGTH + 1];
} User;

typedef struct Block {
    int index;
    time_t timestamp;
    User user_data;
    char previous_hash[SHA256_DIGEST_LENGTH*2 + 1];
    char hash[SHA256_DIGEST_LENGTH*2 + 1];
} Block;

typedef struct {
    Block blockchain[MAX_USERS];
    int blockchain_size;
} Node;

#endif