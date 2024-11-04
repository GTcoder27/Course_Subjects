#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void forkexample()
{
    int x = 1;
    pid_t p = fork();
    if (p < 0)
    {
        perror("fork fail");
        exit(1);
    }
    else if (p == 0)
    {
        printf("Child has x = %d\n", ++x);
        printf("Process ID of Child Process is: %d\n", getpid());
    }
    else
    {
        printf("Parent has x = %d\n", --x);
        printf("Process ID of Parent Process is: %d\n", getpid());
    }
}
int main()
{
    forkexample();
    return 0;
}