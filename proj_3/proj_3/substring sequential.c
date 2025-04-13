
//
// Name: Bren Garcia Marti
// Compiler: Xcode
// Course: CS 4500_001
// Assignment: Proj 3
// Date: 4/8/25
// Problem Statement: Write a program that uses random-number generation and user input to create sentences. The user will enter the noun and adjective but the other words will be generated randomly from words in a file.
//
#include <stdio.h>
#include <stdlib.h> // include rand() input and output char and string see slide 6 of Lect
#include <string.h> // include strcmp()
#include <stdbool.h> // include boolean variables
#include <pthread.h>

#define MAX_INPUT_BYTES 10240
#define MaxLen (2 * InputMaxBytes + 2)
#define NUM_OF_THREADS 10
#define PATH_SIZE 80

int n1, n2;
char *s1, *s2;

//file names and path
const char * STRING_FILE = "strings.txt";
const char * DIRECTORY_PATH = "/Users/Secondary/Desktop/CS4500/CS4500/proj_3/proj_3/"; //have permission to w/r in DOCUMENTS, not in project file

// ~~~ // USER FUNCTION PROTOTYPES // ~~~ //

    // Create a function as defined below to get the file path for each file.Use strcpy and string strcat functions.
    void getFilePath(char* finalPath, const char* directoryPath, const char* fileName);

    // Create a function as defined below that will open the file to read the words as a string then get each word and put it into the word type array. The function will return whether the file was opened successfully. Use strcpy and strtok.
    bool getWordsFromFile(const char* path);

    // Create a function as defined below to count substrings in a segment assigned to a thread
    void countSubstrings(int sillyStringCount) 

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
        puts("So far so good.");
        }

    return 0;
} // end main



// 111 // USER FUNCTION: getWordsFromFile // 111 //
// Create a function as defined below that will open the file to read the words as a string then get each word and put it into the word type array. The function will return whether the file was opened successfully. Use strcpy and strtok.
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
            s1 = (char *)malloc(sizeof(char) * MAX_INPUT_BYTES);
            if (s1 == NULL)
            {   puts("ERROR: Out of memory");
                return -1;
            }
            s2 = (char *)malloc(sizeof(char) * MAX_INPUT_BYTES);
            if (s2 == NULL)
            {   puts("ERROR: Out of memory");
                return -1;
            }
            
            // Read s1 and s2 from the file
            s1 = fgets(s1, MAX_INPUT_BYTES, inPtr);
            s2 = fgets(s2, MAX_INPUT_BYTES, inPtr);
            if (s1 == NULL || s2 == NULL || n1 < n2)
            {   return -1;
            }
            
            n1 = strlen(s1);  // Length of s1
            n2 = strlen(s2) - 1; // Length of s2 (excluding newline)
            
        } // end of while not the end of a file
    } // end of if else

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

// 333 // USER FUNCTION: countSubstrings // 333 //
// Create a function as defined below to count substrings in a segment assigned to a thread
void countSubstrings(int sillyStringCount) {
    int start, end;
    
    start = sillyStringCount * (n1/ NUM_OF_THREADS);
    end = start + (n1/ NUM_OF_THREADS);
    for (int i = start; i <= end - n2; i++)
    {
        int count = 0;
        for (int j = i, k = 0; k < n2; j++, k++)
        {
            if (*(s1 + j) != *(s2 + k))
            {
                break;
            } else {
                count++;
            }
        }
        if (count == n2)
        {
            //countArray[t]++; // Increment count for this thread
        }
    }
}

