#include "BST.h"
#include <assert.h>
#include <string.h>

BSTObj * newBSTObj(char *term);

BSTObj * newBSTObj(char *term) {
	
	BSTObj * temp = (BSTObj *) malloc(sizeof(BSTObj));
	char* temp_string = (char *) malloc((strlen(term) + 1) * sizeof(char));
	
	assert(temp != NULL);
	assert(temp_string != NULL);
	
	strcpy(temp_string, term);
	temp -> term = temp_string;
	temp -> leftChild = NULL;
	temp -> rightChild = NULL;

	return temp;

}


void insert(char *new_data, BSTObj **pBST) {

	BSTObj *temp = NULL;

	if ( *pBST == NULL ) {
		*pBST = newBSTObj(new_data);
	}

	else if ( strcmp(new_data, (*pBST) -> term) == 0 ) {
		temp = (*pBST) -> leftChild;
		(*pBST) -> leftChild = newBSTObj(new_data);
		((*pBST) -> leftChild) -> leftChild = temp;
	}

	else if ( strcmp(new_data, (*pBST) -> term) < 0 ) {
		insert(new_data, &((*pBST) -> leftChild));
	}

	else if ( strcmp(new_data, (*pBST) -> term) > 0) {
		insert(new_data, &((*pBST) -> rightChild));
	}

}


// print to OUT the inorder traversal
void inorderTraverse(FILE *out, BSTObj *T) {

	if ( T == NULL )
		return;
	inorderTraverse(out, T -> leftChild);
	fprintf(out, "%s ", T -> term);
	inorderTraverse(out, T -> rightChild);

}


// print to OUT the preorder traversal
void preorderTraverse(FILE *out, BSTObj *T) {
	
	if ( T == NULL )
		return;
	fprintf(out, "%s ", T -> term);
	preorderTraverse(out, T -> leftChild);
	preorderTraverse(out, T -> rightChild);

}


// print to OUT the postorder traversal
void postorderTraverse(FILE *out, BSTObj *T) {
	
	if ( T == NULL )
		return;
	postorderTraverse(out, T -> leftChild);
	postorderTraverse(out, T -> rightChild);
	fprintf(out, "%s ", T -> term);

}


// print the leaves of the tree in inorder to OUT
void inorderLeaves(FILE *out, BSTObj *T) {

	if ( T == NULL )
		return;
	inorderTraverse(out, T -> leftChild);
	if ( (T -> leftChild) == NULL && (T -> rightChild) == NULL )
		fprintf(out, "%s\n", T -> term);
	inorderTraverse(out, T -> rightChild);

}


// return TRUE if the item_to_find matches a string stored in the tree
int find(char *term_to_find, BSTObj *T) {

    if ( T == NULL )
    	return FALSE;

    if ( strcmp(term_to_find, T -> term) == 0 ) 
       return TRUE;
     
    // Key is greater than root's key 
    if ( strcmp(term_to_find, T -> term) < 0 ) 
       return find(term_to_find, T -> leftChild); 
  
    // Key is smaller than root's key 
    else
    	return find(term_to_find, T -> rightChild); 

}


// compute the height of the tree
// call with height = 0 and root of tree
int treeHeight(BSTObj *T, int height) {

	if ( T == NULL )
		return 0;

	int left = treeHeight(T -> leftChild, height);
	int right = treeHeight(T -> rightChild, height);

	if ( left > right )
		return left + 1;
	return right + 1;

}


// create and return a complete memory independent copy of the tree
BSTObj * copyTree(BSTObj *T) {
	if (T == NULL )
		return T;
    BSTObj * temp = (BSTObj *) malloc(sizeof(BSTObj));
    assert(temp != NULL);
    temp -> term = T -> term;
    temp -> leftChild = copyTree(T -> leftChild);
    temp -> rightChild = copyTree(T -> rightChild);
    return temp;
}


// remove all the nodes from the tree, deallocate space and reset Tree pointer
void makeEmpty(BSTObj **pT) {

	if ( *pT == NULL )
		return;

	else {
		makeEmpty(&((*pT) -> leftChild));
		makeEmpty(&((*pT) -> rightChild));
		free((*pT) -> term);
		(*pT) -> term = NULL;
		free(*pT);
		*pT = NULL;
	}

}