#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listUtil.h"


/*
 * print an individual node, the value and the pointers.
 */
void print_node(NodeObj *node) {

    if (node == NULL ) {
        printf("print_node: no node passed for printing\n");
    }
    else {
        /* for testing using file diff you will likely want to remove ptr value printing */
        printf("Node: value=%d,  node_ptr = %p, prev=%p, next=%p \n",
               node->value, node, node->prev,  node->next);
    }
}


/*
 * traverse list and print each individual node, the value and the pointers.
 */
void traverse_print(NodeObj *list_head) {

    NodeObj *ptr = NULL;  /* show other way to do this */

    ptr = list_head;

    printf("\nList traversal printing all elements of the list \n");
    /* walk down the list printing until we have no more elements */

    while (ptr != NULL) {
        print_node(ptr);
        ptr = ptr->next;        /* what if we don't have this statement? */
    }
    printf("List printing done, end.\n");
}
