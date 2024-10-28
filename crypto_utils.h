#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include "structures.h"

void calculate_hash(Block* block, char* output);
void generate_token(char* token);

#endif