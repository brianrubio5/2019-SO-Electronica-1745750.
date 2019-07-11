#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    FILE* file = fopen("archivo", "a");
    if (file == NULL) {
        fprintf(stderr, "\n Error al cargar el archivo");
    } else {
        int x = fork();
        if (x < 0) {
            fprintf(stderr, "error\n");
            fclose(file);
            exit(1);
        } else if (x == 0) {
            for (int y=0; y<5; y++) 
                fprintf(file, "Escribiendo desde el hijo, #%d\n", y);
        } else {
            /* int z = wait(NULL); */
            for (int y=0; y<5; y++) 
                fprintf(file, "Escribiendo desde el padre, #%d\n", y);
        }
        fclose(file);
    }
    return 0;
}
