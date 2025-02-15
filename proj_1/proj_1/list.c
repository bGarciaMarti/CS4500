//
//  silly list.c
//  proj_1
//
//  Created by Secondary on 1/29/25.
//

#include "list.h"

#define SIZE 50

//Prompts/User Instuctions
const char * prompt1 = "How many elements do you want in this list?\n";

/* Allocate space for a new list and set its head to NULL.
 ∗ Returns the created list if successful, NULL otherwise. */
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
list* create_list(void){

    char myInput[SIZE] = { '\0'}; //char entered by user
    unsigned int choice = 0; // user's menu choice variable, int for switch statement
    
    list* startPtr = malloc(sizeof(list));
    if (startPtr == NULL) { // initially there are no nodes
        puts("Memory allocation failed for list.");
        exit(1);
    }
    startPtr->head = NULL; // initialize the head to NULL
    printMessage(prompt1); //give the user instructions
    
    inputStr(myInput); // get input from user with fgets cmd
    choice = atoi(myInput); // convert the selection into an int for the switch statment
    for (int i = 0; i < choice; i++) // insert elements
    {
        add_to_list(startPtr, "sillyTest");
    }

    if (!isEmpty(startPtr)) // if list is not empty
    { return startPtr;
    }
    else
    { puts("List is empty.\n");
      return NULL;
    }
} // end of create_list

/* Allocates a new node and copies the string from item to this node
∗ (use malloc , strlen , and strncpy; or try strdup). Adds this new node
∗ to end of the list ll . Returns 0 if successful , non−zero otherwise. */
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
int add_to_list ( list* ll , char* item )
{
    node* newPtr = (node*)malloc(sizeof(node)); // create node

   if(newPtr == NULL){
          printf("%s not inserted. No memory available.\n", item);
           return 1;
    }
   // else is space available
      // place values in node
       newPtr->item = strdup(item);
       newPtr->next = NULL; // node does not link to another node YET

       if (ll->head == NULL) {
           ll->head = newPtr;
           return 0;
       }
      // otherwise loop to find the end of the list
       // 'index' through the struct-linked-list by looking at the nextPtr spot for NULL
       node* currentPtr = ll->head;
       while (currentPtr->next != NULL)
      {currentPtr = currentPtr->next; // ... next node
      }
       currentPtr->next = newPtr;   // insert new node
     
    return 0;
} // end of add_to_list()

/* Removes the head of the list ll and move the head of ll to the next node
23 ∗ in the list, extracts the strings to read in the head , and returns a
24 ∗ pointer to this string. Also frees the removed head node . */
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
char* remove_from_list( list *ll){
    // if the list is not empty
    if (ll->head != NULL) {
        node* currentPtr = ll->head;
        char *sillyItem = currentPtr->item; // hold onto node being removed
        ll->head = currentPtr->next; // de-thread the node
        free(currentPtr); // free the de-threaded node
        return (sillyItem);
    }
    else { // the list is empty
        puts("The list is empty.");
        return NULL;
    } //
} // end of remove_from_list

/* Print severy string in each node of the list ll , with a new line
28 ∗ character at the end of each string */
void print_list( list *ll ){
    node* currentPtr = ll->head;
    // if list is empty
    if (isEmpty(ll)) {
       puts("The list is empty.\n");
        return;
    }
    else {
       puts("The list as is:");

       // while not the end of the list
       while (currentPtr != NULL) {
          printf("item: %s --> \n", currentPtr->item);
          currentPtr = currentPtr->next;
       }
       puts("NULL\n");
    }
    return;
} //print_list


/* Flushes (clears) the entire list and re−initializes the list. The passed
∗ pointer ll should still point to a valid, empty list when this function
∗ returns. Any memory allocated to store nodes in the list should be freed.
*/
void flush_list (list *ll){
    node* currentPtr = ll->head;
    
    // while not the end of the list
    while (currentPtr != NULL) {
        char *item = remove_from_list(ll); // Removes the head of the list ll
        free(item);
        // because remove_from_list always replaces the head
        // we can continue to cycle through without moving to the currentPtr-> next
    }
    // make sure the *ll pointer still points to a valid list
    ll->head = NULL;
} // end of flush_list

/* De−allocates all data for the list. Ensure all memory allocated for list
∗ ll is freed, including any allocated strings and list ll itself. */
void free_list( list **ll){
    if(ll != NULL || *ll != NULL){// if the list and the listPtr is not already NULL
        //clear all the nodes
        flush_list(*ll);
        free(*ll); // free the memory allocated for list
        *ll = NULL;
    }
    else {
        return;
    }
} // end of free_list


// ~~~ // printMessage alrogithm // ~~~ //
// print a string array 1 index-element at a time
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
void printMessage(const char* silly_message)
{
    int i = 0;
    for(i = 0; silly_message[i] != '\0'; i++) // while not end-of-string
    {
        printf("%c", silly_message[i]);
    }puts(""); //formatting
} // end of printMessage

// ~~~ // diffInputStr alrogithm // ~~~ //
// Algorithm: // prompt the user // call fgets cmd // retun nothing //
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
void inputStr(char strArray[])
{
    // take input with fgets
    fgets(strArray, 50, stdin); //read the input string using fgets
                //clear the buffer for fgets
                if (strchr(strArray, '\n') == NULL)
                { while ((getchar()) != '\n'); }
            // strip the newline from the string
    if (strArray[0] != 1) // if the data entry is a char data
            {
                strArray[strcspn(strArray, "\n")] = 0; //strip off the \n at the end of the string
            }
    // else the data entry is an int/number of some sort
        
    return;
} // REFERENCE: https://www.geeksforgeeks.org/fgets-gets-c-language/

// ~~~ // isEmpty alrogithm // ~~~ //
// check if the Linked list has any elements in it.
// return 1 if the list is empty, 0 otherwise
// ~~~ // ~~~ // ~~~ // ~~~ // ~~~ //
int isEmpty(list* sillyPtr)
{
   return sillyPtr == NULL;
}
