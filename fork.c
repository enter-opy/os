#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int f = fork();

    if (f > 0) {
        wait(0);

        printf("\nParent process\nOdd numbers\n");

        for (int i = 1; i <= n; i += 2) printf("%d\n", i);

        printf("\n");
    } else {
        printf("\nChild process\nEven numbers\n");

        for (int i = 0; i <= n; i += 2) printf("%d\n", i);

        printf("Child process id is %d\n", getpid());
        printf("Parent process id is %d\n", getppid());
    }

    return 0;
}
