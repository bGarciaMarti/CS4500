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

// ~~~ // insert alrogithm // ~~~ //
// insert new values into the list in sorted order.
// start at the headerPtr, and 'index' through the structs until the correct struct spot is found
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
       while (currentPtr->next != NULL )
      {
         currentPtr = currentPtr->next; // ... next node
      }

     // insert new node
       currentPtr->next = newPtr;
     
   
    return 0;
} // end of add_to_list()











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
