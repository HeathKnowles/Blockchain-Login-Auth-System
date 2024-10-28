#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "structures.h"

void init_blockchain(Node* nodes);
int add_block(Node* nodes, User* user, int user_count);
void distribute_block(Node* nodes, Block* block);
int verify_blockchain(Node* nodes);

#endif
