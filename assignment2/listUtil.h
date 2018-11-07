/*
 * File: listUtil.h
 * Name: Shivansh Rustagi
 * Class: CMPS 12B
 * CruzID: 1651034
 * Description: header file with the function prototypes for list utilities
 */

/*
 * Function: print_node
 * Params:
 *      *node: a node to print
 * Return values:
 *      None
 * Description:
 *      Prints the specified node.
 */
void print_node(NodeObj *node);


/*
 * Function: print_node
 * Params:
 *      *node: a node to print
 * Return values:
 *      None
 * Description:
 *      Prints the specified node.
 */
void traverse_print(NodeObj *list_head);


/*
 * Function: reverse print
 * Params:
 *      *list_head: pointer to list head
 * Return values:
 *      None
 * Description:
 *      travel down the list backwards and print backwards.
 */
void reverse_print(NodeObj *list_head);