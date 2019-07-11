#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    pid_t hpid = fork();
    if (hpid == -1) {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }

    if (hpid == 0) {
        int pipefd[2];
        char buf;

        if (pipe(pipefd) == -1) {
            fprintf(stderr, "Error en funcion pipe()\n");
            exit(EXIT_FAILURE);
        }

        pid_t hhpid = fork();
        if (hhpid == -1) {
            fprintf(stderr, "Error\n");
            exit(EXIT_FAILURE);
        }

        if (hhpid == 0) {
            close(pipefd[1]);

            while (read(pipefd[0], &buf, 1) > 0)
                write(STDOUT_FILENO, &buf, 1);

            write(STDOUT_FILENO, "\n", 1);
            close(pipefd[0]);
            _exit(EXIT_SUCCESS);

        } else {

            char *texto = "Hola hijo\n";
            close(pipefd[0]);
            write(pipefd[1], texto, strlen(texto));
            close(pipefd[1]);
            wait(NULL);
            exit(EXIT_SUCCESS);

        }

    } else {
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}
