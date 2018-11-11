#include <assert.h>
#include "Blockchain.h"

// Exported reference type
struct BlockchainObj {
	Block blocks[100];
}

// constructor for the Blockchain type
Blockchain newBlockchain(void) {
	Blockchain chain = NULL;
	chain = (Blockchain) malloc(sizeof(Blockchain));
	assert(chain != NULL);
	chain -> blocks = NULL;
	return chain;
}

// destructor for the Blockchain type
void freeBlockchain(Blockchain B) {
	Block temp;
	int index = 0;
	temp = (B -> blocks)[index];
	while ( temp != NULL && index < 100 ) {
		freeBlock(temp);
		temp = (B -> blocks)[++index];
	}
}

// append a new block to the chain with the data specified in the new block
// return the size of the block chain if successful and 0 otherwise
int append(Blockchain B, char* data) {
	Block temp;
	int index = 0;
	temp = (B -> blocks)[index];
	while ( temp != NULL && index < 100 )
		temp = (B -> blocks)[++index];
	temp = (B -> blocks)[index - 1];
	return index;
}

// return the number of blocks in this chain
int size(Blockchain B) {
	return 0;
}
// return the block at index idx in the chain
Block get(Blockchain B, int idx) {
	return newBlock("", 0, 0);
}
// check if this is a valid chain by checking the stored previousHash values in each block
// return 1 if valid, 0 otherwise
int valid(Blockchain B) {
	return 0;
}
// shorten the chain by revmoing the last block
// do nothing if the chain is already empty
void removeLast(Blockchain B) {

}

// print the chain
void printBlockchain(FILE* out, Blockchain B) {

}