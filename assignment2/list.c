/*
 * File: list.c
 * Name: Shivansh Rustagi
 * Class: CMPS 12B
 * CruzID: 1651034
 * Description: implementation of functions for list manipulation
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/*
 * Function: create_new_node
 * Params:
 *      id: the value of the node which is to be inserted
 * Return values:
 *      data: pointer to a structure which has been placed in the computer's memory
 * Description:
 *      creates a new NodeObj and allocates its memory with the given ID inserted into the value field, and NULL prev and next pointers
 */
NodeObj *create_new_node(int id) {
	NodeObj *data;
	// Set the pointer to NULL, so that if the malloc fails, the pointer returned is NULL
	data = NULL;
	data = (NodeObj *) malloc(sizeof(NodeObj));
	// Ensure that the malloc actually worked
	assert(data != NULL);
	data -> value = id;
	data -> next = NULL;
	data -> prev = NULL;
	return data;
}


/*
 * Function: insert
 * Params:
 *      **list_head: a pointer to the address of the list head pointer
 *      *to_be_inserted: the NodeObj which is to be inserted into the list
 * Return values:
 *      None
 * Description:
 *      Inserts the given NodeObj into the end of the list
 */
void insert(NodeObj **list_head, NodeObj *to_be_inserted) {
	NodeObj *temp;

	// Handle empty list head address
	if ( list_head == NULL ) {
		fprintf(stderr, "The list is NULL! Please pass a valid list as a parameter.\n");
		return;
	}

	// Handle empty NodeObj insertion attempt
	if ( to_be_inserted == NULL ) {
		fprintf(stderr, "The object to be inserted is NULL! Please insert a valid node.\n");
		return;
	}

	// If the list is empty, set list head to the NodeObj which is to be inserted, and then its prev and null attributes to NULL
	temp = *list_head;
	if ( temp == NULL ) {
		*list_head = to_be_inserted;
		to_be_inserted -> next = NULL;
		to_be_inserted -> prev = NULL;
	}

	else {
		// Cycle through the list to find the end
		while ( temp -> next != NULL )
			temp = temp -> next;
		// Insert the NodeObj
		temp -> next = to_be_inserted;
		to_be_inserted -> prev = temp;
		// Set the end to NULL, just to be safe
		to_be_inserted -> next = NULL;
	}

}


/*
 * Function: ordered_insert
 * Params:
 *      **list_head: a pointer to the address of the list head pointer
 *      *to_be_inserted: the NodeObj which is to be inserted into the list
 * Precondition:
 *		the list must already be sorted, or ordered_insert will simply insert the given 
 *		NodeObj in order according to the first Node it finds which satisfy the conditions defined by the function.
 * Return values:
 *      None
 * Description:
 *      Inserts a node into the increasing value ordered linked list
 */
void ordered_insert(NodeObj **list_head, NodeObj *to_be_inserted) {
	NodeObj *temp;

	// Handle empty list head address
	if ( list_head == NULL ) {
		fprintf(stderr, "The list is NULL! Please pass a valid list as a parameter.\n");
		return;
	}

	// Handle empty NodeObj insertion attempt
	if ( to_be_inserted == NULL ) {
		fprintf(stderr, "The node to be inserted is empty! Please pass a valid node.\n");
		return;
	}

	// If the list is empty, simply perform a normal insert
	if ( *list_head == NULL ) {
		insert(list_head, to_be_inserted);
	}

	// If the NodeObj to be inserted goes at the front of the list, insert it there
	else if( (*list_head) -> value >= to_be_inserted -> value) {
		  to_be_inserted -> next = *list_head;
		  to_be_inserted -> next -> prev = to_be_inserted;
		  *list_head = to_be_inserted;
	}
	
	// Otherwise cycle through the list and seek out the correct spot
	else {
		temp = *list_head;
		// make sure not to go past end of list, and find the correct spot for the NodeObj to be inserted
		while(temp -> next != NULL && temp -> next -> value < to_be_inserted -> value)
			temp = temp -> next;
		to_be_inserted -> next = temp -> next;
		// If not at the end of the list, then link to_be_inserted and the node after it
		if(temp -> next != NULL)
			to_be_inserted -> next -> prev = to_be_inserted;
		temp -> next = to_be_inserted;
		to_be_inserted -> prev = temp;
	}
}


/*
 * Function: delete_all
 * Params:
 *      *list_head: the list head pointer
 * Return values:
 *      None
 * Description:
 *      Removes all the nodes from the list and deallocates the memory allocated to the list.
 */
void delete_all(NodeObj *list_head) {
	// Just keep deleting the list head until there isn't anything left to delete
	while (list_head != NULL)
		delete(&list_head, list_head);
}

/*
 * Function: delete
 * Params:
 *      **list_head: a pointer to the address of the list head pointer
 *      *to_be_deleted: the NodeObj which is to be deleted from the list 
 * Return values:
 *      None
 * Description:
 *      Removes the specified node from the list and deallocates its memory.
 */
void delete(NodeObj **list_head, NodeObj *to_be_deleted) {
	NodeObj *temp;
	NodeObj *delete_temp;
	temp = *list_head;

	// Handle NULL list head pointer address
	if ( list_head == NULL ) {
		fprintf(stderr, "The list is NULL! Please pass a valid list as a parameter.\n");
		return;
	}

	// Handle empty deletion attempt
	if ( to_be_deleted == NULL ) {
		fprintf(stderr, "The node to be deleted is empty! Please pass a valid node.\n");
		return;
	}

	// Handle empty list
	if ( *list_head == NULL ) {
		fprintf(stderr, "The list is empty! Please insert some nodes, and then delete.\n");
		return;
	}

	// If the item to be deleted is at the list_head
	if ( temp == to_be_deleted ) {
		// if there is only one item in the list, free the node and NULL the list
		if ( temp -> next == NULL ) {
			free(*list_head);
			*list_head = NULL;
		} 
		// Otherwise free the node and change the list head pointer and NULL the new list_head's prev
		else {
			delete_temp = temp;
			(temp -> next) -> prev = NULL;
			*list_head = temp -> next;
			free(delete_temp);
		}
	}

	// Otherwise run through the list to find the correct NodeObj to delete
	else {
		while ( temp != to_be_deleted && temp != NULL )
			temp = temp -> next;

		// If temp is NULL, we have reached the end of the list, and the object to be deleted is not in the list. Handle that.
		if ( temp == NULL ) {
			fprintf(stderr, "The object to be deleted isn't in the list! Please try again.\n");
			return;
		}

		else {
			// If temp next is NULL, temp is the last item in the list. Delete it and set the new end of list to temp -> prev
			if ( temp -> next == NULL ) {
				(temp -> prev) -> next = NULL;
				delete_temp = temp;
				free(delete_temp);
			}

			// Otherwise it's somewhere in the middle, handle that.
			else {
				(temp -> prev) -> next = temp -> next;
				(temp -> next) -> prev = temp -> prev;
				delete_temp = temp;
				free(delete_temp);
			}
		}
	}
}
