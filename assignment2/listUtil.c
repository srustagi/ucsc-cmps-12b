#include <stdio.h>
#include "listUtil.h"

void print_node(NodeObj node) {
	printf("Location: %p, value: %d", &node, node.value);
}

void traverse_print(NodeObj *list_head) {
	NodeObj *temp;
	temp = list_head;
	while ( temp != NULL ) {
		print_node(*temp);
		temp = temp -> next;
	}
}