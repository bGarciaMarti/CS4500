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
    
    remove_from_list(listPtr);
    print_list(listPtr);
    
    flush_list(listPtr);
    print_list(listPtr);
    
    free_list(&listPtr);
    print_list(listPtr);
    
    puts("\nEnding Program\nAdios~\n");
    return 0;
} // end main
