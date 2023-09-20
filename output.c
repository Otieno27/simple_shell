#include "shell.h"

void display(const char *message)
{
        write(STDOUT_FILENO, message, strlen(message));
}

