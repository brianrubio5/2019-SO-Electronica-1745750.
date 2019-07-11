#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{ 
    int x = fork();
    if (x < 0 ) {
        fprintf(stderr, "Error\n");
        exit(1);
    } else if (x ==0) {
        printf("Preparando salida estandar(STDOUT_FILENO)...\n\n");
        close(STDOUT_FILENO);
        printf("Imprimiendo despues del descriptor\n");
    } else {
        int y = wait(NULL);
        printf("Trabajo terminado\n\n");
    }
    return 0;
}
