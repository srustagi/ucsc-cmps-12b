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
	chain = (Blockchain) malloc(sizeof(Blockchain));
	assert(chain != NULL);
	chain -> size = 0;
	// for ( index = 0; index < BLOCKCHAIN_SIZE; index ++ ) {
	// 	(chain -> blocks)[index] = NULL;
	// }
	return chain;
}

// destructor for the Blockchain type
void freeBlockchain(Blockchain B) {
	int index = 0;
	Block temp = (B -> blocks)[index];
	if ( B == NULL || valid(B) == 0 ) {
		fprintf(stderr, "Sorry, this is not a valid blockchain. Please pass a valid blockchain and continue.\n");
		return;
	}
	else {
		while ( temp != NULL && index < BLOCKCHAIN_SIZE ) {
			free(temp);
			temp = (B -> blocks)[index++];
		}
	}
}

// append a new block to the chain with the data specified in the new block
// return the size of the block chain if successful and 0 otherwise
int append(Blockchain B, char* data) {
	int index = 0;
	Block temp;
	if ( valid(B) == 0 ) {
		fprintf(stderr, "Sorry, this is not a valid blockchain. Please pass a valid blockchain and continue.\n");
		return 0;
	}
	if ( B == NULL || (B -> blocks)[0] == NULL ) {
		(B -> blocks)[0] = newBlock(data, 0, 0);
	}
	else {
		temp = (B -> blocks)[index];
		while ( temp != NULL && index < BLOCKCHAIN_SIZE ) {
			if ( index == BLOCKCHAIN_SIZE - 1 ) {
				return 0;
			}
			else {
				temp = (B -> blocks)[index++];
			}
		}
		temp = (B -> blocks)[index - 1];
		(B -> blocks)[index] = newBlock(data, (temp -> id) + 1, hash(temp));
	}
	return size(B);
}

// return the number of blocks in this chain
int size(Blockchain B) {
	int index = 0;
	int size;
	Block temp = (B -> blocks)[index];
	if ( B == NULL || valid(B) == 0 ) {
		fprintf(stderr, "Sorry, this is not a valid blockchain. Please pass a valid blockchain and continue.\n");
		return -1;
	}
	else {
		while ( temp != NULL && index < BLOCKCHAIN_SIZE ) {
			size++;
			temp = (B -> blocks)[index++];
		}
	}
	return size;
}
// return the block at index idx in the chain
Block get(Blockchain B, int idx) {
	Block result = NULL;
	if ( B == NULL || valid(B) == 0 ) {
		fprintf(stderr, "Sorry, this is not a valid blockchain. Please pass a valid blockchain and continue.\n");
		return newBlock(NULL, -1, -1);
	}
	else if ( idx < 0 || idx > (BLOCKCHAIN_SIZE - 1) ) {
		fprintf(stderr, "Sorry, this is not a index. Please pass an index equal to or greater than zero, and less than %d.\n", BLOCKCHAIN_SIZE);
		return newBlock(NULL, -1, -1);
	}
	else {
		result = (B -> blocks)[idx];
	}
	return result;
}
// check if this is a valid chain by checking the stored previousHash values in each block
// return 1 if valid, 0 otherwise
int valid(Blockchain B) {
	int index;
	Block temp;
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
		index = 1;
		temp = (B -> blocks)[index];
		while ( temp != NULL && index < (BLOCKCHAIN_SIZE - 1) ) {
			if ( previousHash(temp) != hash((B -> blocks)[index - 1]) ) {
				return 0;
			}
			index++;
		}
	}
	return 1;
}
// shorten the chain by revmoing the last block
// do nothing if the chain is already empty
void removeLast(Blockchain B) {

}

// print the chain
void printBlockchain(FILE* out, Blockchain B) {

}