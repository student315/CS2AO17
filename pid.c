#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_id; //assigns a process ID to caller and parent process.
    pid_t parent_id;
    
    child_id = getpid(); 
    parent_id = getppid();  
    
   //Prints the process ID of caller process and parent process.
    printf("Process ID is:%d. ",child_id);
    printf("Parent process ID is:%d.", parent_id);
    
    return 0;
}
