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

rider_st *create_new_rider(int id, char *first_name, char *last_name, double ave_rating, double distance);
void front_insert(rider_st **list_head, rider_st *to_be_inserted);
void end_insert (rider_st **ptr_to_list_head, rider_st *to_be_inserted);
void ordered_insert (rider_st **ptr_to_list_head, rider_st *to_be_inserted);
void empty(rider_st *list_head);
void delete(rider_st **ptr_to_list_head, rider_st *to_be_deleted);
rider_st find_next_distance_rider( rider_st *list_head, double min_distance);