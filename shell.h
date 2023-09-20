#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void user_input(char *str, size_t script);
void ouput_print(void);
void attain(const char *str);
void output(const char *message);

#endif

