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
        printf("Yo soy el hijo y mi pid es %d\n", getpid());
	int y = wait(NULL);
    } else {
        printf("Yo soy el padre y estoy cerca de esperar\n");
        int y = wait(NULL);
        printf("Yo soy el padre, mi hijo (pid %d) y yo hemos terminado\n", y);
    }
    return 0;
}
