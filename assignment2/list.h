/*
 * File: list.h
 * Name: Shivansh Rustagi
 * Class: CMPS 12B
 * CruzID: 1651034
 * Description: header file with typedef for the NodeObj struct and the function prototypes for list manipulation
 */

typedef struct NodeObj {
	int value;
	struct NodeObj *prev;
	struct NodeObj *next;
} NodeObj;

/*
 * Function: create_new_node
 * Params:
 *      id: the value of the node which is to be inserted
 * Return values:
 *      data: pointer to a structure which has been placed in the computer's memory
 * Description:
 *      creates a new NodeObj and allocates its memory with the given ID inserted into the value field, and NULL prev and next pointers
 */
NodeObj *create_new_node(int id);


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
void insert(NodeObj **list_head, NodeObj *to_be_inserted);


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
void ordered_insert(NodeObj **list_head, NodeObj *to_be_inserted);


/*
 * Function: delete_all
 * Params:
 *      *list_head: the list head pointer
 * Return values:
 *      None
 * Description:
 *      Removes all the nodes from the list and deallocates the memory allocated to the list.
 */
void delete_all(NodeObj *list_head);


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
void delete(NodeObj **list_head, NodeObj *to_be_deleted);
