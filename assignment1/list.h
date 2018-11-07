/*
 File: list.h
 Name: Shivansh Rustagi
 CruzID: 1651034
 Class: CMPS 12B
 Desc: Header file with structure definition and prototypes
*/
struct rider {
	int ID;
	char *first_name;
	char *last_name;
	double ave_rating;
	double distance;
	struct rider *next;
} typedef rider_st;

/*
 * Function: *create_new_rider
 * Params:
 *      id: the ID for the user
 *      *first_name: the user's first name
 *      *last_name: the user's last name
 *      ave_rating: the user's average rating
 *      distance: the distance to the user
 * Return values:
 *      rider: pointer to a structure which has been placed in the computer's memory
 * Description:
 *      creates a new rider_st and allocates its memory with the given information inserted into the fields
 */
rider_st *create_new_rider(int id, char *first_name, char *last_name, double ave_rating, double distance);
/*
 * Function: front_insert
 * Params:
 *      **list_head: the address of the pointer of the head of the list, required so that not just a copy of the data is passed to the function
 *      *to_be_inserted: a pointer to the node which is to be inserted
 * Return values:
 *      None
 * Description:
 *      inserts the specified node into the front of the data structure
 */
void front_insert(rider_st **list_head, rider_st *to_be_inserted);
/*
 * Function: end_insert
 * Params:
 *      **ptr_to_list_head: the address of the pointer of the head of the list, required so that not just a copy of the data is passed to the function
 *      *to_be_inserted: a pointer to the node which is to be inserted
 * Return values:
 *      None
 * Description:
 *      inserts the specified node into the back of the data structure
 */
void end_insert (rider_st **ptr_to_list_head, rider_st *to_be_inserted);
/*
 * Function: ordered_insert
 * Params:
 *      **ptr_to_list_head: the address of the pointer of the head of the list, required so that not just a copy of the data is passed to the function
 *      *to_be_inserted: a pointer to the node which is to be inserted
 * Return values:
 *      None
 * Conditions:
 *      Only works if the list has been created entirely with ordered_insert, as an out of order list does not work with this ORDERED insert. If the list is
 *      not ordered, the insert function simply inserts the node after the first node it is greater than.
 * Description:
 *      inserts the given node into the list based on the “distance” field ordering, least to greatest
 */
void ordered_insert (rider_st **ptr_to_list_head, rider_st *to_be_inserted);
/*
 * Function: empty
 * Params:
 *      *list_head: a pointer to the list head
 * Return values:
 *      None
 * Description:
 *      Deletes every element in the list and deallocates the space for each node.
 */
void empty(rider_st *list_head);
/*
 * Function: delete
 * Params:
 *      **ptr_to_list_head: the address of the pointer to the list head
 *      *to_be_deleted: the node which is to be deleted
 * Return values:
 *      None
 * Description:
 *      Deletes the specified node from the structure
 */
void delete(rider_st **ptr_to_list_head, rider_st *to_be_deleted);
/*
 * Function: find_next_distance_rider
 * Params:
 *      *list_head: the pointer to the head of the list
 *      min_distance: the minimum distance specified
 * Return values:
 *      The node which is the next greatest from the min_distance
 * Description:
 *      returns the node that has the next greater distance value than the min_distance value passed. If there is no matching (greater distance)
 *      node found, a "null node" is returned to signify failure. This has been done because "NULL" cannot be returned.
 */
rider_st find_next_distance_rider( rider_st *list_head, double min_distance);