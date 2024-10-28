#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "crypto_utils.h"
#include <openssl/sha.h>

void calculate_hash(Block* block, char* output) {
    char input[1024];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    
    snprintf(input, sizeof(input), "%d%ld%s%s%s", 
             block->index, 
             block->timestamp, 
             block->user_data.username,
             block->user_data.dob,
             block->previous_hash);
    
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(hash, &sha256);
    
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
}

void generate_token(char* token) {
    for(int i = 0; i < TOKEN_LENGTH; i++) {
        token[i] = '0' + (rand() % 10);
    }
    token[TOKEN_LENGTH] = '\0';
}