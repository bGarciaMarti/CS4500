
//
// Name: Bren Garcia Marti
// Compiler: Xcode
// Course: CS 4500_001
// Assignment: Proj 3
// Date: 4/8/25
// Problem Statement: Write a program that solves a producer-consumer problem using condition variables. The producer thread reads characters one by one from a string stored in a file, then writes sequentially these characters into a circular queue. The consumer thread reads sequentially from the queue and prints them in the same order. Assume a buffer/queue size of 15 characters.
//
#include <stdio.h>
#include <stdlib.h> // include rand() input and output char and string see slide 6 of Lect
#include <string.h> // include strcmp() & strlen()
#include <stdbool.h> // include boolean variables
#include <pthread.h>
#include <semaphore.h>

#define MAX_INPUT_BYTES 10240
#define NUM_OF_THREADS 2
#define PATH_SIZE 80
#define BUFFER_SIZE 15

char *ch;
int count = 0;
int in = 0, out = 0; // in and out pointrs for the circular buffer FIFO, from: Zainab Olalekan
pthread_mutex_t mutex;
sem_t full, empty; // semaphores
char sillyBuffer[BUFFER_SIZE];
bool done = FALSE; // flag to indicate if the producer is done, from: Zainab Olalekan

pthread_t producer_thread, consumer_thread;
pthread_attr_t attr; // set of thread attributes

//file names and path
const char * STRING_FILE = "message.txt";
const char * DIRECTORY_PATH = "/Users/Secondary/Desktop/CS4500/CS4500/proj_3/proj_3/"; //have permission to w/r in DOCUMENTS, not in project file

// ~~~ // USER FUNCTION PROTOTYPES // ~~~ //

    // Create a function as defined below to get the file path for each file.Use strcpy and string strcat functions.
    void getFilePath(char* finalPath, const char* directoryPath, const char* fileName);

    // Create a function as defined below for the producer thread which reads characters one by one from a string stored in a file, then writes sequentially these characters into a circular queue.
    void *producer(void * arg);

    // Create a function as defined below for the consumer thread which reads sequentially from the queue and prints them in the same order.
    void *consumer(void * arg);

// ~~~ // MAIN // ~~~ //

int main(void){
    // initaize data
    pthread_mutex_init(&mutex, NULL); //create the mutex lock
    sem_init(&full, 0, 0); // semaphore full to 0
    sem_init(&empty, 0, BUFFER_SIZE); // semaphore empty to 0
    
    // lengthArray replacement arrays to store the "finalPath" in getFilePath function
    char sillyString_filePath[PATH_SIZE] = { '\0' };

    // get the directory paths to the files
    getFilePath(sillyString_filePath, DIRECTORY_PATH, STRING_FILE);

    // we need the string from the files
    // * pass function pointer and argument seperately for producer(sillyString_filePath);
    pthread_create(&producer_thread, NULL, producer, sillyString_filePath);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    
    // Wait until the threads are done
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    return 0;
} // end main

// 111 // USER FUNCTION: insert // 111 //
// Create a function as defined below too add an item into the buffer
bool insert_into_buffer(char item)
{
    if (count < BUFFER_SIZE) {
        sillyBuffer[in] = item; // buffer logic is FIFO, from: Zainab Olalekan
        in = (in + 1) % BUFFER_SIZE;
        count++;
        return TRUE;
    } else {
        return FALSE;
    }
}

// 222 // USER FUNCTION: remove // 222 //
// Create a function as defined below too remove an item from the buffer
bool remove_from_buffer(char *item)
{
    if (count > 0) {
        *item = sillyBuffer[out]; // buffer logic is FIFO, from: Zainab Olalekan
        out = (out + 1) % BUFFER_SIZE;
        count--;
        return TRUE;
    } else {
        return FALSE;
    }
}

// 333 // USER FUNCTION: producer // 333 //
// Create a function as defined below for the producer thread which reads characters one by one from a string stored in a file, then writes sequentially these characters into a circular queue.
void *producer(void * arg) // buffer logic is FIFO, from: Zainab Olalekan
{   const char *path = (const char *)arg; //cast the argument to a string, from: Zainab Olalekan
    
    puts("PRODUCER BEGINNING");
    FILE *inPtr; //datastream to open
    inPtr = fopen( path, "r");
    if (inPtr == NULL)
    {   printf("%s", "ERROR: File could not be opened.\n");
        exit(1);
    } else {
        ch = (char *)malloc(sizeof(char) * MAX_INPUT_BYTES);
        char sillyCh;
        
        if (ch == NULL)
        {   puts("ERROR: Out of memory");
            exit(1);
        }
        
        while ((sillyCh = fgetc(inPtr)) != EOF) //
        {
            sem_wait(&empty); // retrieve the empty lock if the buffer has space
            pthread_mutex_lock(&mutex); // retrieve the mutex lock to produce item
            
            if (insert_into_buffer(sillyCh)){
                printf("producer produced %c\n", sillyCh);
            } else {
                fprintf(stderr, "WARNING: The buffer is full.\nSome items must be consumed before more production.\n");
                break;
            }
            pthread_mutex_unlock(&mutex);// release the mutex lock
            sem_post(&full); // increment full
        } // end of while not the end of a file
    } // end of if else

    fclose(inPtr); //close the file
    
    // from: Zainab Olalekan
    pthread_mutex_lock(&mutex); //Signal that the producer is done
    done = TRUE;
    pthread_mutex_unlock(&mutex);
    sem_post(&full); // wake up the consumer if waiting
    
    return NULL;
}

// 444 // USER FUNCTION: consumer // 444 //
// Create a function as defined below for the consumer thread which reads sequentially from the queue and prints them in the same order.
void *consumer(void * arg)
{   puts("CONSUMER BEGINNING");
    char sillyCh;
    
    while(TRUE)
    {
        sem_wait(&full); // retrieve the full lock to see if the buffer has an item
        pthread_mutex_lock(&mutex); // retrieve the mutex lock to consume item
        
        // check for termination, from: Zainab Olalekan
        
        if(!remove_from_buffer(&sillyCh) && (done)){
            pthread_mutex_unlock(&mutex);// release the mutex lock
            sem_post(&empty); // increment empty
            break;
        } else {
            printf("consumer consumed %c\n", sillyCh);
        }

    pthread_mutex_unlock(&mutex);// release the mutex lock
    sem_post(&empty); // increment empty
    } // end of a forever loop
    return NULL;
}

// 555 // USER FUNCTION: getFilePath // 555 //
// Create a function as defined below to get the file path for each file. Use strcpy and string strcat functions.
void getFilePath(char * finalPath, const char* directoryPath, const char* fileName)
{
    strcpy(finalPath, directoryPath); // copy directory path symbolic constant into final path
    strcat(finalPath, fileName); //catenate the file name to the end of the file path
    // printf("The path is %s", finalPath); //TESTING
    return;
}

