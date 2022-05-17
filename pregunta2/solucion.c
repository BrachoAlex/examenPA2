#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void handler(int num)
{
    printf("PID de A : %d\n", getpid());
}
int main()
{
    FILE *myfile;
    myfile = fopen("process.pid", "w");

    if (myfile == NULL)
    {
        printf("ERROR");
        return 0;
    }
    fprintf(myfile, "%d", getpid());
    fclose(myfile);
    signal(SIGUSR1, handler);
    pid_t processB = fork();

    if (processB > 0)
    {
        wait(NULL);
    }
    else
    {
        pid_t processC = fork();
        if (processC > 0)
        {
            wait(NULL);
        }
        else
        { 
            printf("PROCESO C. PID : %d, PADRE: %d\n", getpid(), getppid());
            sleep(3);
            FILE *myfile2;
            myfile2 = fopen("process.pid", "r");
            if (myfile2 == NULL)
            {
                printf("ERROR");
                return 0;
            }
            pid_t pid;
            fscanf(myfile, "%d", &pid);
            fclose(myfile);
          
            kill(pid, SIGUSR1);
        }
    }

    printf("\n");
    return 0;
}
