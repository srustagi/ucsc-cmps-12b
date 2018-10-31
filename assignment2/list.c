#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "listUtil.h"

NodeObj *create_new_node(int id) {
	NodeObj *data;
	data = (NodeObj *) malloc(sizeof(NodeObj));
	assert(data != NULL);
	data -> value = id;
	data -> next = NULL;
	data -> prev = NULL;
	return data;
}

void insert(NodeObj **list_head, NodeObj *to_be_inserted) {
	NodeObj *temp;
	temp = *list_head;

	// if ( **list_head == NULL ) {
	// 	fprintf(stderr, "The list is NULL! Please pass a valid list as a parameter.\n");
	// }

	if ( to_be_inserted == NULL ) {
		fprintf(stderr, "The object to be inserted is NULL! Please insert a valid node.\n");
	}

	else if ( temp == NULL ) {
		*list_head = to_be_inserted;
		to_be_inserted -> next = NULL;
		to_be_inserted -> prev = NULL;
	}

	else {
		while ( temp != NULL )
			temp = temp -> next;
		temp -> next = to_be_inserted;
		to_be_inserted -> prev = temp;
		to_be_inserted -> next = NULL;
	}

}
// void ordered_insert(NodeObj **list_head, NodeObj *to_be_inserted);
// void delete_all(NodeObj *list_head);
// void delete(NodeObj **list_head, NodeObj *to_be_deleted);