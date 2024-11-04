#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n;
    printf("Enter the Size of Array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Generated Array:\n");
    for (int a = 0; a < n; a++) {
        arr[a] = rand() % 100; 
        printf("%d\n", arr[a]);
    }
    printf("\n");
    
    int n_processes;
    printf("Enter the Number of Thread you Want: ");
    scanf("%d", &n_processes);

    for (int i = 0; i < n_processes; i++) {
        pid_t pid = fork();
        if (pid < 0 ) {
          
            fprintf(stderr, "Fork failed!\n");
            exit(1);
        } 
        else if (pid == 0) {
            int sum = 0;
            int elements_per_process = (n + n_processes - i - 1) / n_processes; 
            for (int j = i; j < n; j += n_processes) {
                sum += arr[j];
            }
            printf("Thread %d : Sum of Array Elements: %d\n", i+1,  sum);
            exit(0); 
        }
    }

    return 0;
}