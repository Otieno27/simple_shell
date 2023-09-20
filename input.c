#include "shell.h"

void user_input(char *str, size_t script){
        if(fgets(str, script,stdin) == NULL){
                if(feof(stdin)) {
                        display("\n");
                        exit(EXIT_SUCCESS);
                }
                else{
                        display("Invalid input!\n");
                        exit(EXIT_FAILURE);
                }
        }
        str[strcspn(str, "\n")] = '\0'; for removing newline
}

