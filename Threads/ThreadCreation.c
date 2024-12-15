//1. Basic Thread Creation
//Objective: Familiarize yourself with creating threads.
//Instructions:
//Write a C program that creates three threads.
//Each thread should print a message, including its thread ID, to indicate it is running (e.g., "Thread X is running").
//Ensure the main thread waits for each of the threads to complete using pthread_join.
//Expected Output: Each thread prints a message, and the program exits only after all threads are complete.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* print_message(void* arg) {
    pthread_t id = pthread_self();
    printf("Thread with ID = %lu is executing\n", id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    if (pthread_create(&thread1, NULL, print_message, NULL) != 0) {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, print_message, NULL) != 0) {
        perror("Failed to create thread 2");
        return 1;
    }

    if (pthread_create(&thread3, NULL, print_message, NULL) != 0) {
        perror("Failed to create thread 3");
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

    if (pthread_join(thread3, NULL) != 0) {
        perror("Failed to join thread 3");
        return 1;
    }

    printf("All threads have finished execution\n");

    return 0;
}
