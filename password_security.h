#ifndef PASSWORD_SECURITY_H
#define PASSWORD_SECURITY_H

#include <stdint.h>
#include <openssl/sha.h>

#define SALT_LENGTH 16
#define HASH_LENGTH 64
#define COMBINED_LENGTH (SALT_LENGTH + HASH_LENGTH)
#define WORK_FACTOR 12

typedef struct {
    unsigned char salt[SALT_LENGTH];
    unsigned char hash[HASH_LENGTH];
} PasswordHash;

void generate_salt(unsigned char* salt);
void hash_password_with_salt(const char* password, const unsigned char* salt, PasswordHash* ph);
int verify_password(const char* password, const PasswordHash* stored_hash);

#endif