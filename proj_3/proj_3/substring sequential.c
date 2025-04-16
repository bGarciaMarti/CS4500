
//
// Name: Bren Garcia Marti
// Compiler: Xcode
// Course: CS 4500_001
// Assignment: Proj 3
// Date: 4/8/25
// Problem Statement: Write a program to find out the number of substrings in string s1 that is exactly the same as s2.
//
#include <stdio.h>
#include <stdlib.h> // include rand() input and output char and string see slide 6 of Lect
#include <string.h> // include strcmp() & strlen()
#include <stdbool.h> // include boolean variables
#include <pthread.h>

#define MAX_INPUT_BYTES 10240
#define NUM_OF_THREADS 10
#define PATH_SIZE 80

int n1, n2;
char *s1, *s2;
int count = 0;
pthread_mutex_t lock;

//file names and path
const char * STRING_FILE = "strings.txt";
const char * DIRECTORY_PATH = "/Users/Secondary/Desktop/CS4500/CS4500/proj_3/proj_3/"; //have permission to w/r in DOCUMENTS, not in project file

// ~~~ // USER FUNCTION PROTOTYPES // ~~~ //

    // Create a function as defined below to get the file path for each file.Use strcpy and string strcat functions.
    void getFilePath(char* finalPath, const char* directoryPath, const char* fileName);

    // Create a function as defined below that will open the file to read the words as a string then get each word and put it into the word type array. The function will return whether the file was opened successfully. Use strcpy and strtok.
    bool getWordsFromFile(const char* path);

    // Create a function as defined below to count substrings in a segment assigned to a thread
    void *countSubstrings(void *sillyStringCount);

// ~~~ // MAIN // ~~~ //

int main(void){
    bool retrievedWords = false;
    pthread_t threads[NUM_OF_THREADS];
    pthread_mutex_init(&lock, NULL);
    
    // lengthArray replacement arrays to store the "finalPath" in getFilePath function
    char sillyString_filePath[PATH_SIZE] = { '\0' };

    // get the directory paths to the files
    getFilePath(sillyString_filePath, DIRECTORY_PATH, STRING_FILE);

    // we need the strings from the files
    retrievedWords = getWordsFromFile(sillyString_filePath);
    if (retrievedWords == false) {
        printf("%s", "ERROR: File could not be opened.\n");
            return 0;
        }
    
    // use pthread functions to divide up the task
    for (int i = 0; i < NUM_OF_THREADS; i++) {
        pthread_create(&threads[i], NULL, countSubstrings, (void *)(i * n1 / NUM_OF_THREADS));
    }
    for (int i = 0; i < NUM_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("There are %d substrings of %s in the string %s", count, s2,s1);
    
    // free the allocated memory after use
    free(s1);
    free(s2);
    pthread_mutex_destroy(&lock);
    
    return 0;
} // end main



// 111 // USER FUNCTION: getWordsFromFile // 111 //
// Create a function as defined below that will open the file to read the words as a string then get each word and put it into the word type array. The function will return whether the file was opened successfully. Use strcpy and strtok.
bool getWordsFromFile(const char* path)
{
    bool functioningFile = false;
    
    FILE *inPtr; //datastream to open
    inPtr = fopen( path, "r");
    if (inPtr == NULL)
    {
        functioningFile = false;
    } else {
        functioningFile = true;
        while (!feof(inPtr) && (s1 == NULL)) //while not the end of a file and while the s1 is empty
        {
            s1 = (char *)malloc(sizeof(char) * MAX_INPUT_BYTES);
            if (s1 == NULL)
            {   puts("ERROR: Out of memory");
                exit(1);
            }
            s2 = (char *)malloc(sizeof(char) * MAX_INPUT_BYTES);
            if (s2 == NULL)
            {   puts("ERROR: Out of memory");
                exit(1);
            }
            
            // read s1 and s2
            s1 = fgets(s1, MAX_INPUT_BYTES, inPtr);
            s2 = fgets(s2, MAX_INPUT_BYTES, inPtr);
            n1 = (int)strlen(s1) - 1; // exclude /n
            n2 = (int)strlen(s2) - 1; // exclude /n
            
            if (s1 == NULL || s2 == NULL || n1 < n2) // Assume that n1 is at least twice as long as n2.
            {   puts("ERROR: strings s1, s2 or len(n1) len(n2)");
                exit(1);
            }
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
void *countSubstrings(void *sillyStringCount) {
    
    // Assume that n1 is at least twice as long as n2
    // indexStart = sillyStringCount * ( n1 / NUM_OF_THREADS);
    // indexEnd = start + (n1 / NUM_OF_THREADS);
    
    for (int i = (int)sillyStringCount; i < (int)sillyStringCount + n1 / NUM_OF_THREADS; i++)
    {
        if(!strncmp(s1 + i, s2, n2)) {
            pthread_mutex_lock(&lock);
            count++;
            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}


