#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

void fun_execl();
void fun_execle();
void fun_execlp();
void fun_execv();
void fun_execvp();
void fun_execvP();

int main(int argc, char *argv[] )
{ 
    int x = fork();
    if (x < 0 ) {
        fprintf(stderr, "Error\n");
        exit(1);
	fun_execvP();
    } else if (x ==0) {
        printf("\nPreparando llamada\"ls -a ..\"\n");
    } else {
        int y = wait(NULL);
        printf("\nProceso terminado\"ls -a ..\"\n");
    }
    return 0;
}

void fun_execl()
{
    execl("/bin/ls", "ls", "-a", "..", NULL);
}

void fun_execle()
{
    char *arg[4];
    arg[0] = strdup("/bin/ls");
    arg[1] = strdup("ls");
    arg[2] = strdup("..");
    arg[3] = NULL;
    execle(arg[0], arg[1], arg[2], arg[3], arg);}

void fun_execlp()
{
    execlp("/bin/ls", "ls", "-a", "..", NULL);
}

void fun_execv()
{
    char *arg[4];
    arg[0] = strdup("ls");
    arg[1] = strdup("-a");
    arg[2] = strdup("..");
    arg[3] = NULL;
    execvp(arg[0], arg);
}

void fun_execvp()
{
    char *arg[4];
    arg[0] = strdup("ls");
    arg[1] = strdup("-a");
    arg[2] = strdup("..");
    arg[3] = NULL;
    execvp(arg[0], arg);
}
void fun_execvP()
{
    char *arg[4];
    arg[0] = strdup("ls");
    arg[1] = strdup("-a");
    arg[2] = strdup("..");
    arg[3] = NULL;
    execvP(arg[0], "/bin", arg);
}
