//
//  silly list.h
//  proj_1
//
//  Created by Secondary on 1/29/25.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h> // include rand() input and output char and string see slide 6 of Lect
#include <string.h> // include strcmp()
#include <stdbool.h> // include boolean variables


// ~~ // START OF THE ASSIGNMENT GIVEN CODE // ~~ //

/* Declaring all the structs */
typedef struct Node node ;

struct Node {
    char *item ;
    node *next ; // pointer to next node
    } ;

typedef struct List {
    node *head ;
    } list ;
// typedef list *listPtr; // synonym for list*

/* Allocate space for a new list and set its head to NULL.
 ∗ Returns the created list if successful, NULL otherwise. */
list* create_list(void);

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

// ~~ // END OF THE ASSIGNMENT GIVEN CODE // ~~ //

// print a string array 1 index-element at a time
void printMessage(const char* silly_message);

// prompt the user // call fgets cmd // retun nothing //
void inputStr(char strArray[]);

// check if the Linked list has any elements in it.
// return 1 if the list is empty, 0 otherwise
int isEmpty(list* sillyPtr);


#endif /* list_h */

