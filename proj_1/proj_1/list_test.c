//
// Name: Bren Garcia Marti
// Compiler: Xcode
// Course: CS 4500_002
// Assignment: Project 1 Linked Lists
//  Created by BGarcia on 1/28/25
// Problem Statement:
//
#include "list.h"


int main(void)
{
    
    list* listPtr = malloc(sizeof(list));
    
    listPtr = create_list();
    print_list(listPtr);
    
    remove_from_list(listPtr);
    print_list(listPtr);
    
    remove_from_list(listPtr); /* I encounter an error:
                                proj_1(32895,0x1000ebe00) malloc: *** error for object 0x10050cce0: pointer being freed was not allocated
                                */
    print_list(listPtr);
    
    
    /*
     I don't work :C
    flush_list(listPtr);
    print_list(listPtr);
     */
    
    puts("\n\nEnding Program\nAdios~\n");
    return 0;
} // end main
