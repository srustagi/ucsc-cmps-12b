/*
*BST.c
*
*Description
*	Contains methods to deal with Binary Search Trees
*
*methods
*	void insert
*	void inorderTraverse
*	void preorderTraverse
*	void postorderTraverse
*	void inorderLeaves
*	int find
*	int treeHeight
*	BSTObj* copyTree
*	void makeEmpty
*
*Author
*	Mehul Varma
*	mvarma4
*Class
*	CMPS-12B
*
*Date
*	11/18/18
*	
*/

#include <string.h>
#include <assert.h>
#include "BST.h"


/* adds a new node to the BST with the new_data values, space must be allocated in the BST node */

/*
 *insert
 *
 *Description
 *	adds a new node to the BST with the new_data values, space must be allocated in the BST node
 *
 *Input
 *	new_data - string for the new node
 *	**pBST = pointer to the pointer of the 1st node of the tree
 *
 *Output
 *	void - adds node to the tree
 */
void insert(char *new_data,  BSTObj **pBST){

	if( pBST == NULL){
		fprintf( stderr , "insert - Invalid Input\n");
		return;
	}

	if ( new_data != NULL){
		
	        if ( *pBST == NULL){

			BSTObj *ptr = *pBST;
			ptr = (BSTObj *) malloc(sizeof(BSTObj));

	                char newStr =   (char) calloc(strlen(new_data) , sizeof(char));

        	        int i;
        	        for(i = 0; i < strlen(new_data); i++){
        	                newStr[i] = new_data[i];
        	        }
	
        	        newStr[i+1] = '\0';
			ptr->term = newStr;
	                *pBST = ptr;
			return;
		}

		if ( strcmp( new_data , (*pBST)->term) <= 0){

			insert( new_data , &( (*pBST)->leftChild) );
		}
	
		else {
			insert( new_data , &( (*pBST)->rightChild) );
		}
		return;
	}

	else{
		fprintf( stderr , "insert - Invalid Input\n");
	}

}

/*
 *inorderTraverse
 *
 *Description
 *	print to OUT the inorder traversal
 *
 *Input
 *	out - handle to output file
 *	*T - pointer to the tree
 *
 *Output
 *	void - just prints the tree inorder traversal
 */
void inorderTraverse(FILE *out, BSTObj *T){

	if ( out == NULL){
		fprintf( stderr , "inorderTraverse - Handle to output file is NULL");
		return;
	}

	if ( T == NULL){
		return;
	}

	inorderTraverse( out , T->leftChild);
	fprintf( out ,"%s " , T->term);
	inorderTraverse( out , T->rightChild);

}

/*
 *preorderTraverse
 *
 *Description
 *	print to OUT the preorder traversal
 *
 *Input
 *	out - handle to output file
 *	*T - pointer to the tree
 *
 *Output
 *	void - just prints the tree preorder traversal
 */
void preorderTraverse(FILE *out, BSTObj *T){

	if ( out == NULL){
		fprintf( stderr , "preorderTraverse - Handle to output file is NULL");
		return;
	}

	if ( T == NULL){
		return;
	}

	fprintf( out ,"%s " , T->term);
	preorderTraverse( out , T->leftChild);
	preorderTraverse( out , T->rightChild);
}


/*
 *postorderTraverse
 *
 *Description
 *	print to OUT the postorder traversal
 *
 *Input
 *	out - handle to output file
 *	*T - pointer to the tree
 *
 *Output
 *	void - just prints the tree postorder traversal
 */
void postorderTraverse(FILE *out, BSTObj *T){
	
	if ( out == NULL){
		fprintf( stderr , "postorderTraverse - Handle to output file is NULL");
		return;
	}

	if ( T == NULL){
		return;
	}

	postorderTraverse( out , T->leftChild);
	postorderTraverse( out , T->rightChild);
	fprintf( out ,"%s " , T->term);
}


/*
 *inorderLeaves
 *
 *Description
 *	print the leaves of the tree in inorder to OUT
 *
 *Input
 *	out - handle to output file
 *	*T - pointer to the tree
 *
 *Output
 *	void - just prints the leave nodes of the tree inorder
 */
void inorderLeaves(FILE *out, BSTObj *T){
	
	if ( out == NULL){
		fprintf( stderr , "inorderLeaves - Handle to output file is NULL");
		return;
	}

	if ( T == NULL){
		return;
	}
	
	inorderLeaves( out , T->leftChild);

	if ((T->leftChild == NULL) && (T->rightChild == NULL)){
		fprintf( out ,"%s\n" , T->term);
	}

	inorderLeaves( out , T->rightChild);
}


/*
 *find
 *
 *Description
 *	return TRUE if the item_to_find matches a string stored in the tree
 *
 *Input
 *	term_to_find - string to find in tree
 *	*T - pointer to the tree
 *
 *Output
 *	returns 1 if true, 0 if false
 */
int find(char *term_to_find, BSTObj *T){

	if ( term_to_find == NULL){
		fprintf( stderr , "find - pointer to term is null");
	}

	if ( T != NULL){
		
		if ( strcmp( term_to_find , T->term) == 0){
			return TRUE;
		}

		else if ( strcmp( term_to_find , T->term) < 0){
			return find( term_to_find , T->leftChild);
		}

		else if ( strcmp( term_to_find , T->term) > 0){
			return find( term_to_find , T->rightChild);
		}

		return FALSE;
	}

	else {
		return FALSE;
	}
}

/*
 *treeHeight
 *
 *Description
 *	computes the height of the tree
 *
 *Input
 *	height - current height of the tree while computing
 *	*T - pointer to the tree
 *
 *Output
 *	returns height of the tree starting from 0
*/
int treeHeight(BSTObj *T, int height){


	if ( T != NULL){
	
		if ( T->leftChild == NULL && T->rightChild == NULL){
			return height;
		}

		int max_left = 0;
		int max_right = 0;

		if ( T->leftChild != NULL) max_left = treeHeight( T->leftChild , 1 + height);
		if ( T->rightChild != NULL) max_right = treeHeight( T->rightChild , 1 + height);
	
		if ( max_left > max_right) return max_left;
		else return max_right;

	}

	else {
		fprintf( stderr , "Invalid Input\n");
		return;
	}
} 

/*
 *copyTree
 *
 *Description
 *	computes the height of the tree
 *
 *Input
 *	*T - pointer to the tree
 *
 *Output
 *	returns height of the tree starting from 0
*/
BSTObj * copyTree(BSTObj *T){

	if ( T == NULL){
		return T;
	}

	BSTObj * temp = (BSTObj *) malloc(sizeof(BSTObj));
	temp -> term = (char *) malloc((strlen(T -> term) + 1) * sizeof(char));

	assert(temp != NULL);
	assert(temp -> term != NULL);

	strcpy(temp -> term, T -> term);
	temp -> leftChild = copyTree(T -> leftChild);
	temp -> rightChild = copyTree(T -> rightChild);
	return temp;	

}

/*
 *makeEmpty
 *
 *Description
 *	removes all the nodes from the tree, deallocates space and reset Tree pointer
 *
 *Input
 *	**pT - pointer to the pointer to the tree
 *
 *Output
 *	no output - just frees the tree
*/
void makeEmpty(BSTObj **pT){

	if( *pT != NULL){

		BSTObj *ptr1 = NULL;
		BSTObj *ptr2 = NULL;

		ptr1 = (*pT)->leftChild;
		ptr2 = (*pT)->rightChild;
			
		makeEmpty( &ptr1);
		makeEmpty( &ptr2);

		free((*pT)->term);
		free(*pT);

		return;		
	}
	
	return;
}

/*
 *findLeftMost
 *
 *Description
 *	finds the left most child node connected to node passed, helper method for deleteItem
 *
 *Input
 *	**pT - pointer to the node whose left most child node is to be returned
 *
 *Output
 *	left most child node is returned
*/
BSTObj* findLeftMost ( BSTObj *T){

	if(T->leftChild != NULL){
                return findLeftMost(T->leftChild);
        }
        else{
                return T;
        }
}



/*
 *deleteItem
 *
 *Description
 *	deletes the node in the binary search tree, whose term matches the term passed in the function
 *
 *Input
 *	**pT - pointer to the pointer to the tree
 *	*term_to_delete - the term, whose node has to be deleted from the tree if it exists in it
 *
 *Output
 *	no output - just deletes the node from the tree
*/
int deleteItem (char *term_to_delete, BSTObj **pT){

	/* check if pointer passed is NULL */
	if ( pT == NULL){
		fprintf(stderr, "Null pointer passed.\n");
		return 0;
	}

	/* check if the term passed, whose node has to deleted, is NULL*/ 
	if ( term_to_delete == NULL) {
		fprintf(stderr, "Null string passed.\n");
		return 0;
	}

	/* if pointer passed is to an empty tree, nothing can be deleted, error statement is printed*/
	if ( *pT == NULL){
		fprintf(stderr , "Cannot delete from empty tree\n");
		return 0;
	}

	/* check is the term passed matches to the term of any node in the tree*/
	if(find(term_to_delete, *pT) == 0){
		fprintf(stderr, "Can't find the item.\n");
		return 0;
	}

	int cmp = strcmp((*pT)->term, term_to_delete);

	/* if node to be deleted is on the left subtree of current node (*pT), the function recurses until it finds the node to be deleted and deletes it using the else statement of this fucnction */
	if(cmp > 0){
		deleteItem(term_to_delete, &((*pT)->leftChild));
        }
	/* if node to be deleted is on the right subtree of current node (*pT), the function recurses until it finds the node to be deleted and deletes it using the else statement of this fucnction */
	else if(cmp < 0){
		deleteItem(term_to_delete, &((*pT)->rightChild));
	}

	/* if node to be deleted is the currrent node passed (*pT)*/
	else{
    
		/* if node to be deleted has no children nodes*/
		if ( (*pT)->rightChild == NULL && (*pT)->leftChild == NULL){

			BSTObj* temp = *pT;
			free(temp->term);
			free(temp);
			*pT = NULL;
		}

		/* if node to be deleted has only rightChild */
		else if ( (*pT)->rightChild != NULL && (*pT)->leftChild == NULL){
			
			BSTObj* temp = *pT;
			*pT = (*pT)->rightChild;
			free(temp);
			temp = NULL;
		}

		/* if node to be deleted has only leffChild */
		else if ( (*pT)->rightChild == NULL && (*pT)->leftChild != NULL){
			BSTObj* temp = *pT;
			*pT = (*pT)->leftChild;
			free(temp);
			temp = NULL;

		}

		/* if node to be deleted has two children nodes */
		/* swap the term of the head of the tree with the left most child of the right child, and delete that node from the tree */
                else{
			BSTObj* temp = findLeftMost( (*pT)->rightChild);
			strcpy((*pT)->term , temp->term);
                       	deleteItem(temp->term, (&((*pT)->rightChild)));  
			temp = NULL;
		}

		return 1;
	}

}