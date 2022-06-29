#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void sigHandler(int sig);

int main()
{
    pid_t pid;
    pid = getpid();

    printf("pid: %d\n", pid);
    struct sigaction action;
    sigset_t set;
    action.sa_handler = sigHandler;
    sigfillset(&action.sa_mask);
    action.sa_flags = SA_RESTART;

    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(SIG_BLOCK, &set, NULL);
    for(;;)
    {
        sleep(10);
    }
    sigprocmask(SIG_UNBLOCK, &set, NULL);

    return 0;
}

void sigHandler(int sig)
{
    if(sig == SIGUSR1)
    {
        printf("Receied USR1 signal\n");
    }
    else if(sig == SIGUSR2)
    {
        printf("Receied USR2 signal\n");
    }
}