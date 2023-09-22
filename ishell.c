#include "shell.h"
#include <ctype.h> // Include for isatty function

/**
 * Check if the shell is in interactive mode.
 * @param info: Pointer to the shell information struct
 * @return 1 if in interactive mode, 0 otherwise
 */
int isShellInteractive(info_t *info) {
    int isInteractive = isatty(STDIN_FILENO) && info->readFileDescriptor <= 2;
    return isInteractive;
}

/**
 * Check if a character is a delimiter.
 * @param character: The character to check
 * @param delimiterString: The delimiter string to compare against
 * @return 1 if character is a delimiter, 0 otherwise
 */
int isCharacterDelimiter(char character, const char *delimiterString) {
    while (*delimiterString) {
        if (*delimiterString == character) {
            return 1;
        }
        delimiterString++;
    }
    return 0;
}

/**
 * Check if a character is alphabetic.
 * @param character: The character to check
 * @return 1 if character is alphabetic, 0 otherwise
 */
int isAlphabeticCharacter(int character) {
    return isalpha(character);
}

/**
 * Convert a string to an integer.
 * @param str: The string to be converted
 * @return 0 if no numbers in string, converted number otherwise
 */
int customAtoi(const char *str) {
    int i = 0;
    int sign = 1;
    int result = 0;
    int flag = 0;

    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    for (; str[i] != '\0' && flag != 2; i++) {
        if (isdigit(str[i])) {
            flag = 1;
            result *= 10;
            result += (str[i] - '0');
        } else if (flag == 1) {
            flag = 2;
        }
    }

    return sign * result;
}

