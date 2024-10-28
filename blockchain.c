#include <string.h>
#include <time.h>
#include "blockchain.h"
#include "crypto_utils.h"

void init_blockchain(Node* nodes) {
    for(int i = 0; i < MAX_NODES; i++) {
        nodes[i].blockchain_size = 0;
    }
}

int add_block(Node* nodes, User* user, int user_count) {
    Block new_block;
    new_block.index = user_count;
    new_block.timestamp = time(NULL);
    new_block.user_data = *user;
    
    if(user_count == 0) {
        strcpy(new_block.previous_hash, "0");
    } else {
        strcpy(new_block.previous_hash, nodes[0].blockchain[user_count-1].hash);
    }
    
    calculate_hash(&new_block, new_block.hash);
    distribute_block(nodes, &new_block);
    
    return verify_blockchain(nodes);
}

void distribute_block(Node* nodes, Block* block) {
    for(int i = 0; i < MAX_NODES; i++) {
        nodes[i].blockchain[nodes[i].blockchain_size++] = *block;
    }
}

int verify_blockchain(Node* nodes) {
    char computed_hash[SHA256_DIGEST_LENGTH*2 + 1];
    
    for(int i = 1; i < nodes[0].blockchain_size; i++) {
        Block* current_block = &nodes[0].blockchain[i];
        Block* previous_block = &nodes[0].blockchain[i-1];
        
        // Verify previous hash
        if(strcmp(current_block->previous_hash, previous_block->hash) != 0) {
            return 0;
        }
        
        // Verify current hash
        calculate_hash(current_block, computed_hash);
        if(strcmp(computed_hash, current_block->hash) != 0) {
            return 0;
        }
    }
    
    return 1;
}