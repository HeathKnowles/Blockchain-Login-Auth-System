#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include "password_security.h"

void generate_salt(unsigned char* salt) {
    if (RAND_bytes(salt, SALT_LENGTH) != 1) {
        fprintf(stderr, "Error generating random salt\n");
        exit(1);
    }
}

void hash_password_with_salt(const char* password, const unsigned char* salt, PasswordHash* ph) {
    memcpy(ph->salt, salt, SALT_LENGTH);
    
    if (PKCS5_PBKDF2_HMAC(
            password, strlen(password),
            salt, SALT_LENGTH,
            100000,  // iterations
            EVP_sha512(),
            HASH_LENGTH,
            ph->hash
        ) != 1) {
        fprintf(stderr, "Error hashing password\n");
        exit(1);
    }
}

int verify_password(const char* password, const PasswordHash* stored_hash) {
    PasswordHash computed_hash;
    hash_password_with_salt(password, stored_hash->salt, &computed_hash);
    return memcmp(computed_hash.hash, stored_hash->hash, HASH_LENGTH) == 0;
}