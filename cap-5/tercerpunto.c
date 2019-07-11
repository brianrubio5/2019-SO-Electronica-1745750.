#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) 
{
    int x = fork();
    if (x < 0) {
        fprintf(stderr, "Error \n");
        exit(1);
    } else if (x == 0) {
        printf("\nHijo: hello\n");
    } else {
        time_t timer, delay;
        time(&timer);
        delay = timer + .01;
        while (difftime(delay, timer) >= 0)
            time(&timer);
        printf("Padre: goodbye\n\n");
    }
    return 0;
}
