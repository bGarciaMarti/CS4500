
//
// Name: Bren Garcia Marti
// Compiler: Xcode
// Course: CS 2060_001
// Assignment: HW06 Mad Libs
// Date: 4/3/2022
// Problem Statement: Write a program that uses random-number generation and user input to create sentences. The user will enter the noun and adjective but the other words will be generated randomly from words in a file.
//
#include <stdio.h>
#include <stdlib.h> // include rand() input and output char and string see slide 6 of Lect
#include <string.h> // include strcmp()
#include <stdbool.h> // include boolean variables
#include <ctype.h> // include toupper
#include <time.h> // to see the function randomly
#include <pthread.h>

#define MAX 10240
#define NUM_THREADS 10
#define PATH_SIZE 80

int n1, n2;
char *s1, *s2;
FILE *fp;


//file names and path
const char * STRING_FILE = "strings.txt";
const char * DIRECTORY_PATH = "/Users/bdenny/Documents/"; //have permission to w/r in DOCUMENTS, not in project file

// ~~~ // USER FUNCTION PROTOTYPES // ~~~ //

    // Create a function as defined below to get the file path for each file.Use strcpy and string strcat functions.
    void getFilePath(char* finalPath, const char* directoryPath, const char* fileName);

    // Create a function as defined below that will open the file to read the words as a string then get each word and put it into the word type array (article, verb, preposition). The function will return whether the file was opened successfully. Use strcpy and strtok.
    bool getWordsFromFile(const char* path, char words[][WORD_LENGTH], int numberWords);


// ~~~ // MAIN // ~~~ //

int main(void){
    bool retrievedWords = false;

    // lengthArray replacement arrays to store the "finalPath" in getFilePath function
    char sillyString_filePath[PATH_SIZE] = { '\0' };

    // get the directory paths to the files
    getFilePath(sillyString_filePath, DIRECTORY_PATH, STRING_FILE);

    // we need the strings from the files
    retrievedWords = getWordsFromFile(sillyString_filePath);
    if (retrievedWords == false)
        {
        printf("%s", "ERROR: File could not be opened.\n");
        } else {

        }

    return 0;
} // end main



// 111 // USER FUNCTION: getWordsFromFile // 111 //
// Create a function as defined below that will open the file to read the words as a string then get each word and put it into the word type array (article, verb, preposition). The function will return whether the file was opened successfully. Use strcpy and strtok.
bool getWordsFromFile(const char* path)
{
    bool functioningFile = false;
    
    FILE *inPtr; //datastream to open
    inPtr = fopen( path, "r"); //r for read
    if (inPtr == NULL)
    {
        functioningFile = false;
        return 0;
    } else {
        while (!feof(inPtr)) //while not the end of a file
        {
            s1 = (char *)malloc(sizeof(char) * MAX);
            if (s1 == NULL)
            {   puts("ERROR: Out of memory");
                return -1;
            }
            s2 = (char *)malloc(sizeof(char) * MAX);
            if (s2 == NULL)
            {
                puts("ERROR: Out of memory");
                return -1;
            }
              }
         }
    }
    //TESTING double check the array
    //for (i = 0; i < numberWords ; i++)
    //{
    //   printf("The words now in the array are: %s\n",  words[i]);
    //}
    fclose(inPtr); //close the file
    return functioningFile;
}

// 222 // USER FUNCTION: getFilePath // 222 //
// Create a function as defined below to get the file path for each file. Use strcpy and string strcat functions.
void getFilePath(char * finalPath, const char* directoryPath, const char* fileName)
{

    strcpy(finalPath, directoryPath); // copy directory path symbolic constant into final path
    strcat(finalPath, fileName); //catenate the file name to the end of the file path
    // printf("The path is %s", finalPath); //TESTING
    return;
}