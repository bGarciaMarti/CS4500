//
//  main.c
//  CS4500 Proj 1
//
//  Created by Secondary on 1/28/25.
//

/* Declari n g a l l t h e s t r u c t s */
typedef struct Node node ;

struct Node {
    char *item ;
    node *next ;
    } ;

typedef struct List {
    node *head ;
    } list ;

/* Allocate space for a new list and set its head to NULL.
 ∗ Returns the created list if successful, NULL otherwise. */
list* create_list();

/* Allocates a new node and copies the string from item to this node
∗ (use malloc , strlen , and strncpy; or try strdup). Adds this new node
∗ to end of the list ll . Returns 0 if successful , non−zero otherwise. */
int add_to_list ( list* ll , char* item ) ;

/* Removes the head of the list ll(and move the head of ll to the next node
23 ∗ in the list), extra cts the strings to red in the head , and returns a
24 ∗ pointer to this string. Also frees the removed head node . */
char* remove_from_list( list *ll) ;

/* Print severy string in each node of the list ll , with a new line
28 ∗ character at the end of each string */
void print_list( list *ll ) ;

/* Flushes (clears) the entire list and re−initializes the list. The passed
∗ pointer ll should still point to a valid, empty list when this function
∗ returns. Any memory allocated to store nodes in the list should be freed.
*/
void flush_list (list *ll) ;

/* De−allocates all data for the list. Ensure all memory allocated for list
∗ ll is freed, including any allocated strings and list ll itself. */
void free_list( list **lls) ;
