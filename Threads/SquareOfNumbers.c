//4. Calculating Square of Numbers in Parallel
//Objective: Demonstrate simple tasks that can run in parallel.
//Instructions:
//Create an array of integers (e.g., [1, 2, 3, 4, 5]).
//For each number in the array, create a thread that calculates its square
// and prints the result (e.g., "Square of 2 is 4").
//Wait for all threads to finish before the main program exits.
//Expected Output: Each thread prints the square of its assigned number.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* square(void* arg) {
    int number = *(int*) arg;
    printf("Square of %d is %d\n", number, number*number);
    return NULL;
}

int main() {
    #define SIZE 5
    int arr[SIZE] = {1, 2, 3, 4, 5};
    pthread_t threads[SIZE];

    for (int i = 0; i < SIZE; i++) {
        if (pthread_create(&threads[i], NULL, square, arr+i) != 0) {
            perror("Failed to create thread 1");
            return 1;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join a thread");
            return 1;
        }
    }
    printf("All threads have finished execution\n");

    return 0;
}
