#include <assert.h>
#include "Blockchain.h"
#define BLOCKCHAIN_SIZE 100

// Exported reference type
struct BlockchainObj {
	Block blocks[BLOCKCHAIN_SIZE];
	int size;
};

struct BlockObj {
	char* data;
	int id;
	long hash;
};

// constructor for the Blockchain type
Blockchain newBlockchain(void) {
	Blockchain chain = NULL;
	int index;
	chain = (Blockchain) malloc(sizeof(struct BlockchainObj));
	assert(chain != NULL);
	chain -> size = 0;
	for ( index = 0; index < BLOCKCHAIN_SIZE; index++ ) {
		(chain -> blocks)[index] = NULL;
	}
	return chain;
}

// destructor for the Blockchain type
void freeBlockchain(Blockchain B) {
	int index;
	for ( index = 0; index < (size(B)); index++ ) {
		free(get(B, index));
	}
}

// append a new block to the chain with the data specified in the new block
// return the size of the block chain if successful and 0 otherwise
int append(Blockchain B, char* data) {
	Block temp;
	int result;
	if ( size(B) == BLOCKCHAIN_SIZE) {
		result = 0;
	}
	else if ( (size(B)) == 0 ) {
		(B -> blocks)[0] = newBlock(data, 0, 0);
		(B -> size)++;
		result = size(B);
	}
	else {
		temp = (B -> blocks)[size(B) - 1];
		(B -> blocks)[size(B)] = newBlock(data, 1 + (temp -> id), hash(temp));
		(B -> size)++;
		result = size(B);
	}
	return result;
}

// return the number of blocks in this chain
int size(Blockchain B) {
	return B -> size;
}
// return the block at index idx in the chain
Block get(Blockchain B, int idx) {
	return (B -> blocks)[idx];
}
// check if this is a valid chain by checking the stored previousHash values in each block
// return 1 if valid, 0 otherwise
int valid(Blockchain B) {
	int index;
	if ( B == NULL ) {
		fprintf(stderr, "Sorry, this is an empty blockchain. Please pass a valid blockchain and continue.\n");
		return 0;
	}
	if ( (B -> blocks)[1] == NULL ) {
		if ( previousHash((B -> blocks)[0]) == 0 )
			return 1;
		else
			return 0;
	}
	else {
		for (index = 1; index < size(B) - 1; index++)	{
			if ( previousHash((B -> blocks)[index]) != hash((B -> blocks)[index - 1])) {
				return 0;
			}
		}
	}
	return 1;
}
// shorten the chain by revmoing the last block
// do nothing if the chain is already empty
void removeLast(Blockchain B) {
	(B != NULL && valid(B)) ? (freeBlock((B -> blocks)[--(B -> size)])) : (fprintf(stderr, "NULL or Invalid Blockchain.\n"));
}

// print the chain
void printBlockchain(FILE* out, Blockchain B) {
	int index;
	for (index = 0; index < (size(B)); index++) {
		printBlock(out, get(B, index));
	}
}