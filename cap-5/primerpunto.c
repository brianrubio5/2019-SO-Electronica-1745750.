#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int var = 100;
    int x = fork();
    if (x < 0) {
        fprintf(stderr, "Error\n");
        exit(1);
    } else if (x == 0) {
        printf("leyendo variable del hijo: %d\n", var);
        var += 50;
        printf("leyendo variable del hijo: %d\n", var);
    } else {
        int y = wait(NULL);
        printf("leyendo variable del padre: %d\n", var);
        var++;
        printf("leyendo variable del padre: %d\n", var);
    }
    return 0;
}
