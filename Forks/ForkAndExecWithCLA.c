#include <unistd.h>
#include <sys/wait.h>
#include "utils.h"

//Assignment 4: Fork and Exec with Command-Line Arguments
//Objective: Use fork and execl to run a command with multiple arguments.
//Prepare a test.txt file with some text.
//
// Write a program that:
//Uses fork to create a child process.
//The child process should use execl to run the grep command
//to search for a specific word (e.g., "main") in a text file (e.g., test.txt).
//The parent process should print "Parent process completed".
//Expected Output: The lines in the file test.txt that contain
//the word "main" followed by "Parent process completed". (edited)


int main(void) {
    const int pid = fork();
    check_fork_result(pid);

    if (pid) {
        printf("Parent process done\n");
        wait(NULL);
    } else {
        int ret = execl("/bin/grep", "grep", "main", "test.txt", NULL);
        check_exec_result(ret);
    }
    return 0;
}