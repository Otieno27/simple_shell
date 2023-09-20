#include "shell.h"

void attain(const char *input){
        pid_t pid = fork();


        if(pid == -1){
                perror("fork");
                exit(EXIT_FAILURE);
        }
        else if(pid == 0){
                execlp(input, input, (char *)NULL);
                perror("execlp");
                exit(EXIT_FAILURE);
        }
        else{
                wait(NULL); //ppid//
        }
}

