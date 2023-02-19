#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int pfds1[2]; 
    int pfds2[2];
    pipe(pfds1); 
    pipe(pfds2);  

    if (!fork()) {
        close(1);  
        dup(pfds1[1]);  
        close(pfds1[0]), close(pfds1[1]), close(pfds2[0]), close(pfds2[1]);  
        execlp("ls", "ls", NULL);  
    }
    else {
        if (!fork()) {
            close(0);  
            dup(pfds1[0]);  
            close(pfds1[0]), close(pfds1[1]), close(pfds2[1]);  
            execlp("cut", "cut", "-b", "1-3", NULL); 
        }
        else {
            
            close(0);  
            dup(pfds2[0]);  
            close(pfds1[0]), close(pfds1[1]), close(pfds2[0]), close(pfds2[1]);  
            execlp("sort", "sort", NULL);  
        }
    }
    return 0;
}
