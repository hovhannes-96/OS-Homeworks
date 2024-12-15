//3. Printing Numbers with Threads
//Objective: Practice thread creation and task division without synchronization.
//Instructions:
//Write a program that creates three threads.
//Each thread should print numbers from 1 to 5, along with its thread ID.
//Observe that the order of printing may vary between runs, showing the concurrent execution.
//Expected Output: Each thread prints numbers from 1 to 5, but in potentially varying orders.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* print(void* arg) {
    for (int i = 1; i <= 5; i++) {
      printf("%d %lu\n", i, pthread_self());
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    if (pthread_create(&thread1, NULL, print, NULL) != 0) {
        perror("Failed to create thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, print, NULL) != 0) {
        perror("Failed to create thread 2");
        return 1;
    }

    if (pthread_create(&thread3, NULL, print, NULL) != 0) {
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
        perror("Failed to join thread 2");
        return 1;
    }
    printf("All threads have finished execution\n");

    return 0;
}
