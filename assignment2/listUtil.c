/*
 * File: listUtil.c
 * Name: Shivansh Rustagi
 * Class: CMPS 12B
 * CruzID: 1651034
 * Description: implementations of list utilities
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "listUtil.h"


/*
 * Function: print_node
 * Params:
 *      *node: a node to print
 * Return values:
 *      None
 * Description:
 *      Prints the specified node.
 */
void print_node(NodeObj *node) {
    if (node == NULL ) {
        printf("print_node: no node passed for printing\n");
    }
    else {
        /* for testing using file diff you will likely want to remove ptr value printing */
        printf("Node: value = %d,  node_ptr = %p, prev = %p, next = %p \n", node->value, node, node->prev, node->next);
    }
}


/*
 * Function: traverse_print
 * Params:
 *      *list_head: pointer to list head
 * Return values:
 *      None
 * Description:
 *      Traverse through the list and print all nodes.
 */
void traverse_print(NodeObj *list_head) {
    NodeObj *ptr;
    ptr = list_head;

    printf("\nList traversal printing all elements of the list \n");
    /* walk down the list printing until we have no more elements */

    while (ptr != NULL) {
        print_node(ptr);
        ptr = ptr->next;        /* what if we don't have this statement? */
    }
    printf("List printing done, end.\n");
}


/*
 * Function: reverse print
 * Params:
 *      *list_head: pointer to list head
 * Return values:
 *      None
 * Description:
 *      travel down the list backwards and print backwards.
 */
void reverse_print(NodeObj *list_head) {
    NodeObj *ptr;
    ptr = list_head;

    while (ptr -> next != NULL) {
        ptr = ptr->next;
    }

    while (ptr != NULL) {
        print_node(ptr);
        ptr = ptr -> prev;
    }
}
