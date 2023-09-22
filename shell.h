#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void user_input(char *str, size_t script);
void display_prompt(void);
void attain(const char *str);
void output(const char *message);

char **_getenv(const char *var)
void free_env(void)
char **_copyenv(void)

int customAtoi(const char *str);
int isCharacterDelimiter(char character, const char *delimiterString);
int isShellInteractive(info_t *info);


int displayHelp(info_t *info);
int changeDirectory(info_t *info);
int exitShell(info_t *info);

#endif

