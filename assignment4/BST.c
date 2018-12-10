/*
 * File: BST.c
 * Name: Shivansh Rustagi
 * Class: CMPS 12B
 * CruzID: shrustag
 * ID Number: 1651034
 * Description: implementations of BST functions
 */

#include "BST.h"
#include <assert.h>
#include <string.h>


/*
 * Function: newBSTObj
 * Params:
 *      char * term: the value of the term for the node to be inserted
 * Return values:
 *      temp: a BSTObj with the specified data as the term and NULL left and right children 
 * Description:
 *      Helper function to allocate space for and create nodes in insert()
 */
BSTObj * newBSTObj(char * term);
BSTObj * findLeftMostChild(BSTObj * T);
void deleteNode(BSTObj ** T);
BSTObj * get(char * term_to_find, BSTObj * T);

BSTObj * get(char * term_to_find, BSTObj * T) {
	if ( strcmp(term_to_find, T -> term) == 0 ) 
	   return T;
	 
	// if term_to_find is lexographically less than the term at T, search the left subtree
	if ( strcmp(term_to_find, T -> term) < 0 ) 
		return get(term_to_find, T -> leftChild); 
  
	// if term_to_find is lexographically greater than the term at T, search the right subtree
	else
		return get(term_to_find, T -> rightChild);
}

void deleteNode(BSTObj ** T) {
	free(T);
	* T = NULL;
}

BSTObj * findLeftMostChild(BSTObj * T) {
	BSTObj * temp = T;
	if ( temp -> leftChild == NULL ) {
		return temp;
	}
	while (temp -> leftChild != NULL) { 
		temp = temp -> leftChild; 
	}
	return temp;
}

// see prototype for newBSTObj above
BSTObj * newBSTObj(char * term) {
	
	// allocate space for the string and BSTObj
	BSTObj * temp = (BSTObj *) malloc(sizeof(BSTObj));
	char * temp_string = (char *) malloc((strlen(term) + 1) * sizeof(char));
	
	// check for successful allocation
	assert(temp != NULL);
	assert(temp_string != NULL);
	
	// store data in the BSTObj
	strcpy(temp_string, term);
	temp -> term = temp_string;
	temp -> leftChild = NULL;
	temp -> rightChild = NULL;

	// success!
	return temp;

}


/*
 * Function: insert
 * Params:
 *      char * new_data: the String to insert into the tree
 *      BSTObj ** pBST: the pointer to the address of the BST to insert into
 * Return values:
 *      None
 * Description:
 *      Inserts the specified data into a new node into the tree.
 */
void insert(char * new_data, BSTObj ** pBST) {

	if ( new_data == NULL ) {
		fprintf(stderr, "Sorry, the String to be inserted is NULL, please pass a valid String.\n");
		return;
	}

	if ( pBST == NULL ) {
		fprintf(stderr, "Sorry, the pointer to the tree root is NULL, please pass a valid BST.\n");
		return;
	}

	// used to handle the case if new_data is already in the tree
	BSTObj *temp = NULL;

	// if the tree pointer is NULL
	if ( *pBST == NULL ) {
		*pBST = newBSTObj(new_data);
	}

	// if new_data is already in the tree
	else if ( strcmp(new_data, (*pBST) -> term) == 0 ) {
		temp = (*pBST) -> leftChild;
		(*pBST) -> leftChild = newBSTObj(new_data);
		((*pBST) -> leftChild) -> leftChild = temp;
	}

	// if new_data is lexographically less than the term of the current node
	else if ( strcmp(new_data, (*pBST) -> term) < 0 ) {
		insert(new_data, &((*pBST) -> leftChild));
	}

	// if new_data is lexographically more than the term of the current node
	else if ( strcmp(new_data, (*pBST) -> term) > 0) {
		insert(new_data, &((*pBST) -> rightChild));
	}

}


/*
 * Function: inorderTraverse
 * Params:
 *      FILE * out: the file to write to
 *      BSTObj * T: the BST to print
 * Return values:
 *      None
 * Description:
 *      Prints the tree using an inorder traversal.
 */
void inorderTraverse(FILE * out, BSTObj * T) {

	if ( out == NULL ) {
		fprintf(stderr, "Sorry, the file to write to is NULL, please pass a valid file.\n");
		return;
	}

	if ( T == NULL )
		return;
	inorderTraverse(out, T -> leftChild);
	fprintf(out, "%s ", T -> term);
	inorderTraverse(out, T -> rightChild);

}


/*
 * Function: preorderTraverse
 * Params:
 *      FILE * out: the file to write to
 *      BSTObj * T: the BST to print
 * Return values:
 *      None
 * Description:
 *      Prints the tree using a preorder traversal.
 */
void preorderTraverse(FILE *out, BSTObj *T) {
	
	if ( out == NULL ) {
		fprintf(stderr, "Sorry, the file to write to is NULL, please pass a valid file.\n");
		return;
	}

	if ( T == NULL )
		return;
	fprintf(out, "%s ", T -> term);
	preorderTraverse(out, T -> leftChild);
	preorderTraverse(out, T -> rightChild);

}


/*
 * Function: postorderTraverse
 * Params:
 *      FILE * out: the file to write to
 *      BSTObj * T: the BST to print
 * Return values:
 *      None
 * Description:
 *      Prints the tree using a postorder traversal.
 */
void postorderTraverse(FILE *out, BSTObj *T) {

	if ( out == NULL ) {
		fprintf(stderr, "Sorry, the file to write to is NULL, please pass a valid file.\n");
		return;
	}
	
	if ( T == NULL )
		return;
	postorderTraverse(out, T -> leftChild);
	postorderTraverse(out, T -> rightChild);
	fprintf(out, "%s ", T -> term);

}


/*
 * Function: inorderLeaves
 * Params:
 *      FILE * out: the file to write to
 *      BSTObj * T: the BST whose leaves to print
 * Return values:
 *      None
 * Description:
 *      Prints the leaves of the BST using a preorder traversal.
 */
void inorderLeaves(FILE *out, BSTObj *T) {

	if ( out == NULL ) {
		fprintf(stderr, "Sorry, the file to write to is NULL, please pass a valid file.\n");
		return;
	}

	if ( T == NULL )
		return;
	inorderLeaves(out, T -> leftChild);
	if ( (T -> leftChild) == NULL && (T -> rightChild) == NULL )
		fprintf(out, "%s ", T -> term);
	inorderLeaves(out, T -> rightChild);

}


/*
 * Function: find
 * Params:
 *      char * term_to_find: the term to find in the BST
 *      BSTObj * T: the BST to search
 * Return values:
 *      TRUE or FALSE as defined in BST.h
 * Description:
 *      Searches the BST for the specifed value.
 */
int find(char * term_to_find, BSTObj * T) {

	if ( term_to_find == NULL ) {
		fprintf(stderr, "Sorry, the String to be found is NULL, please pass a valid String.\n");
		return FALSE;
	}

	// if T is empty, return FALSE
	if ( T == NULL )
		return FALSE;

	// if the term at T is equal to term_to_find, return TRUE
	if ( strcmp(term_to_find, T -> term) == 0 ) 
	   return TRUE;
	 
	// if term_to_find is lexographically less than the term at T, search the left subtree
	if ( strcmp(term_to_find, T -> term) < 0 ) 
	   return find(term_to_find, T -> leftChild); 
  
	// if term_to_find is lexographically greater than the term at T, search the right subtree
	else
		return find(term_to_find, T -> rightChild); 

}


/*
 * Function: treeHeight
 * Params:
 *      BSTObj * T: the tree whose height to calculate
 *      int height: the current height of the Tree, used in recursion
 * Return values:
 *      TRUE or FALSE as defined in BST.h
 * Description:
 *      Searches the BST for the specifed value.
 */
int treeHeight(BSTObj * T, int height) {

	if ( T == NULL ) {
		return 0;
	}

	// handle incorrect height pass
	if ( height < 0 ) {
		fprintf(stderr, "Sorry, the passed height value is negative. Please pass a zero or positive height with the function.\n");
		return -1;
	}

	// return the height if the node is a leaf
	if ( T -> leftChild == NULL && T -> rightChild == NULL )
		return height + 1;

	// initialize partial sums for recursive height calculation
	int left = 0;
	int right = 0;

	// compute the max heights of each left and right subtree
	if ( T -> leftChild != NULL )
		left = treeHeight(T -> leftChild, height + 1);
	if ( T -> rightChild != NULL )
		right = treeHeight(T -> rightChild, height + 1);

	if ( left > right)
		return left;
	return right;

}


/*
 * Function: copyTree
 * Params:
 *      BSTObj * T: the tree to copy
 * Return values:
 *      temp: a pointer to a BST
 * Description:
 *      Creates a memory independent copy of BST T.
 */
BSTObj * copyTree(BSTObj * T) {

	if ( T == NULL )
		return T;

	// allocate space for the copy BST and the term in each node
	BSTObj * temp = (BSTObj *) malloc(sizeof(BSTObj));
	temp -> term = (char *) malloc((strlen(T -> term) + 1) * sizeof(char));

	// check for correct allocations
	assert(temp != NULL);
	assert(temp -> term != NULL);

	// copy the term from the original node into its corresponding node in the copied tree, and then copy the subtrees
	strcpy(temp -> term, T -> term);
	temp -> leftChild = copyTree(T -> leftChild);
	temp -> rightChild = copyTree(T -> rightChild);
	
	// success
	return temp;

}


/*
 * Function: makeEmpty
 * Params:
 *      BSTObj ** pT: the tree to empty
 * Return values:
 *      None
 * Description:
 *      Empty out the tree: deallocate space and NULL the pointer to it.
 */
void makeEmpty(BSTObj ** pT) {

	if ( pT == NULL ) {
		fprintf(stderr, "Sorry, the pointer to the tree root is NULL, please pass a valid BST.\n");
		return;
	}

	if ( *pT == NULL )
		return;

	else {
		// empty the left and right children
		makeEmpty(&((*pT) -> leftChild));
		makeEmpty(&((*pT) -> rightChild));
		// free the term of the node
		free((*pT) -> term);
		(*pT) -> term = NULL;
		// free the node itself
		free(*pT);
		*pT = NULL;
	}

}


int deleteItem (char *term_to_delete, BSTObj **pT){
	BSTObj * T = *pT;
	if(T == NULL){
		fprintf(stderr, "ERROR: node does not exist in tree");
		return FALSE;
	}
	int cmp = strcmp(T->term, term_to_delete);
	if(cmp > 0)
			return deleteItem(term_to_delete, &((*pT)->leftChild));
	else if(cmp < 0)
			return deleteItem(term_to_delete, &((*pT)->rightChild));
	else{
			if(T->leftChild == NULL && T->rightChild == NULL){
					free((*pT)->term);
					free(*pT);
					(*pT)->term = NULL;
					*pT = NULL;
			}
			else if(T->leftChild == NULL){
					BSTObj *tmp = *pT;
					*pT = (*pT)->rightChild;
					free(tmp->term);
					free(tmp);
			}
			else if(T->rightChild == NULL){
					BSTObj *tmp = *pT;
					*pT = (*pT)->leftChild;
					free(tmp->term);
					free(tmp);
			}
			else{
					BSTObj *tmp = findLeftMostChild(T->rightChild);
					T->term = tmp->term;
					return deleteItem(T->term, &(T->rightChild));
			}
	}
	return TRUE;
}

// int deleteItem (char *term_to_delete, BSTObj **pT) {
// 	int status = 1;
// 	BSTObj * temp = NULL;
// 	BSTObj * deleteTemp = NULL;

// 	if ( pT == NULL ) {
// 		fprintf(stderr, "Sorry, the pointer to the tree address is NULL. Please pass a valid pointer.\n");
// 		return status;
// 	}

// 	if ( *pT == NULL ) {
// 		fprintf(stderr, "Sorry, the tree is empty. Please insert some nodes and try again.\n");
// 		return status;
// 	}

// 	if ( term_to_delete == NULL) {
// 		fprintf(stderr, "Sorry, the string you're searching for is NULL. Please pass a valid string and try again.\n");
// 		return status;
// 	}

// 	if ( find(term_to_delete, *pT) == FALSE ) {
// 		fprintf(stderr, "Sorry, the string you are searching for is not in the tree.\n");
// 		return status;
// 	}

// 	temp = get(term_to_delete, *pT);
// 	// zero children
// 	if ( (temp) -> leftChild == NULL && (temp) -> rightChild == NULL) {
// 		printf("before free\n");
// 		free(temp);
// 		printf("after free\n");
// 		// temp = NULL;
// 		printf("succuess\n");
// 	}
		
	
// 	status = 0;
// 	return status;
// }
