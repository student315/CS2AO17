#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int counter = 0; //global variable set
int main() {
    pid_t pID;
    
    pID = fork(); // child process created.

    if (pID < 0) { // Checking if the fork was accomplished successfully.
        printf("Fork has failed due to an error.\n");
        exit(1);
    }
    
    else if (pID == 0) {//child process being printed.
        for (int i = 0; i < 20; i++) { // counter incremented.
            printf("The child process counter is %d\n", ++counter);
            usleep(100); // The process is paused for 100 miliseconds.
        }
    }
    
    else { //Parent process being printed. 
        for (int i = 0; i < 20; i++) {
            printf("The parent process counter is %d\n", ++counter);
            usleep(100); //Same pause here too.
        }
    }
    return 0;
}
