#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int x = fork();
    if (x < 0) {
        fprintf(stderr, "Error\n");
        exit(1);
    } else if (x == 0) {
        printf("Soy el hijo, mi pid es  %d\n", getpid());
    } else {
        printf("Soy el padre y estoy esperando mi hijo de pid %d\n", x);
        int y = waitpid(x, NULL, WUNTRACED);
        printf("Soy el padre y mi hijo (pid %d) y yo hemos terminado\n", y);
    }
    return 0;
}
