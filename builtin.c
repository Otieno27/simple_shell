#include "shell.h"

int exitShell(info_t *info) {
    int exitStatus = 0;

    if (info->argv[1]) {
        char *exitArg = info->argv[1];
        int exitCode = _erratoi(exitArg);

        if (exitCode == -1) {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(exitArg);
            _eputchar('\n');
            return 1; // Error occurred
        }

        info->err_num = exitCode;
    } else {
        info->err_num = -1;
    }

    return -2; // Indicates the shell should exit
}

int changeDirectory(info_t *info) {
    char *currentDir, *targetDir, buffer[1024];
    int chdirResult;

    currentDir = getcwd(buffer, sizeof(buffer));
    if (!currentDir) {
        _puts("Error: Unable to get current directory.\n");
        return 1; // Error occurred
    }

    if (!info->argv[1]) {
        targetDir = _getenv(info, "HOME=");
        if (!targetDir) {
            targetDir = _getenv(info, "PWD=");
        }

    } else if (_strcmp(info->argv[1], "-") == 0) {
        targetDir = _getenv(info, "OLDPWD=");
        if (!targetDir) {
            _puts(currentDir);
            _putchar('\n');
            return 0;
        }

    } else {
        targetDir = info->argv[1];
    }

    chdirResult = chdir(targetDir);
    if (chdirResult == -1) {
        print_error(info, "Error: Unable to change directory to ");
        _eputs(targetDir);
        _eputchar('\n');
        return 1; // Error occurred
    }

    _setenv(info, "OLDPWD", _getenv(info, "PWD="));
    _setenv(info, "PWD", getcwd(buffer, sizeof(buffer)));

    return 0;
}

int displayHelp(info_t *info) {
    _puts("Shell Help: This shell is a basic command-line interpreter.\n");
    _puts("Available commands:\n");
    _puts("  exit [status] - Exit the shell with an optional status code.\n");
    _puts("  cd [directory] - Change the current directory.\n");
    _puts("  help - Display this help message.\n");
    return 0;
}

