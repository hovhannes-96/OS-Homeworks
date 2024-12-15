//2. Array Processing with Threads
//Objective: Practice dividing an array processing task among multiple threads.
//Instructions:
//Create an array of integers with a few values.
//Write a function that calculates the sum of part of this array.
//Use two threads: assign each half of the array to a different thread.
//Each thread should calculate the sum of its half and print it.
//Expected Output: Two separate partial sums printed by each thread.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

typedef struct {
    int* arr;
    int size;
} ThreadData;

void* sum(void* arg) {
  int sum = 0;
    ThreadData* data = (ThreadData*)arg;
    for (int i = 0; i < data->size; i++) {
      sum += data->arr[i];
    }
    printf("Sum from thread with ID = %lu: %d\n", pthread_self(), sum);
    return NULL;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ThreadData data1 = {arr, 3};
    ThreadData data2 = {arr + 3, 7};
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, sum, (void*)&data1) != 0) {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, sum, (void*)&data2) != 0) {
        perror("Failed to create thread 2");
        return 1;
    }

    if (pthread_join(thread1, NULL) != 0) {
        perror("Failed to join thread 1");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0) {
        perror("Failed to join thread 2");
        return 1;
    }
    printf("All threads have finished execution\n");

    return 0;
}
