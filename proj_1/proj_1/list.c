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
    
    list* startPtr = NULL; // initially there are no nodes
    
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
//void insert(petListPtr *sillyPtr, char sillyName[SIZE], int sillyAge)
int add_to_list ( list* ll , char* item )
{
    node* newPtr = (node*)malloc(sizeof(node)); // create node

   if (newPtr != NULL) { // is space available
      // place values in node
       newPtr->item = strdup(item);
       newPtr->next = NULL; // node does not link to another node YET

       node* previousPtr = NULL;
       node* currentPtr = (list **) ll;
       
      // loop to find the end of the list
       // 'index' through the struct-linked-list by looking at the nextPtr spot for NULL
    while (currentPtr != NULL )
      {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->next; // ... next node
      }
      
     // insert new node between previousPtr and currentPtr
    previousPtr->next = newPtr;
    newPtr->next = currentPtr;
     }
   else {
      printf("%s not inserted. No memory available.\n", item);
       return 1;
   }
    return 0;
} // end of insert()











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
