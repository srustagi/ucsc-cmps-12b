/*
 * File: list.h
 * Name: Shivansh Rustagi
 * Class: CMPS 12B
 * CruzID: 1651034
 * Description: header file with typedef for the NodeObj struct and the function prototypes for list manipulation
 */

/*
 * 
 */
typedef struct NodeObj {
	int value;
	struct NodeObj *prev;
	struct NodeObj *next;
} NodeObj;


NodeObj *create_new_node(int id);
void insert(NodeObj **list_head, NodeObj *to_be_inserted);
void ordered_insert(NodeObj **list_head, NodeObj *to_be_inserted);
void delete_all(NodeObj *list_head);
void delete(NodeObj **list_head, NodeObj *to_be_deleted);