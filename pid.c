#include <stdio.h>
#include <unistd.h>

int main(void)
{
        pid_t pid;

        pid = getpid();
        printf("%u\n", pid);
        return 0;
}

