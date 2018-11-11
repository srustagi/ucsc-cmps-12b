#include <assert.h>
#include <string.h>
#include "Block.h"

struct BlockObj {
	char* data;
	int id;
	long hash;
};

// constructor for the Block type, create the space for the data, make a copy!
Block newBlock(char* data, int id, long hash) {
	Block block_ptr = (Block) malloc(sizeof(Block));
	assert(block_ptr != NULL);
	block_ptr -> data = data;
	block_ptr -> id = id;
	block_ptr -> hash = hash;
	return block_ptr;
}

// destructor for the Block type
void freeBlock(Block B) {
	if ( B != NULL ) {
		free(B);
		return;
	}
	else {
		fprintf(stderr, "The Block passed was NULL, please pass a valid block.\n");
		return;
	}
}

// return a pointer to this block's data.
// It would probably be better to return a copy to avoid, easy erroneous manipulation of blocks,
// but for demonstration purposes we are going to expose the actual block data.
char* data(Block B) {
	char* result = NULL;
	if ( B != NULL ) {
		result = B -> data;
	}
	else {
		fprintf(stderr, "The Block passed was NULL, please pass a valid block.\n");
	}
	return result;
}

// return the stored previousHash from this block
long previousHash(Block B) {
	long result = -1;
	if ( B != NULL ) {
		result = B -> hash;
	}
	else {
		fprintf(stderr, "The Block passed was NULL, please pass a valid block.\n");
	}
	return result;
}

// recomute the hash value for this block
long hash(Block B) {
	long result = -1;
	int index;
	if (B != NULL) {
		result = (B -> id) + (B -> hash);
		for (index = 0; index < strlen(B -> data); index++) {
			result += ((int) (B -> data)[index]);
		}
	}
	else {
		fprintf(stderr, "The Block passed was NULL, please pass a valid block.\n");
	}
	return result;
}

// print the block id and data
// (NOTE: for debugging purposes you may want to have it also print the hash and previousHash values during development.)
void printBlock(FILE* out, Block B) {
	fprintf(out, "%d:%s\n", B -> id, B -> data);
}