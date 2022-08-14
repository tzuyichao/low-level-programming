#define _GNU_SOURCE 
#include <stdlib.h> 
#include <stdio.h> 
#include <signal.h> 
#include <sched.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * Example from Containerization with LXC
 * User Namespace
 */

static int childFunc(void *arg)
{
    printf("UID inside the namespace is %ld\n", (long)geteuid());
    printf("GID inside the namespace is %ld\n", (long)getegid());
}

static char child_stack[1024*1024];

void main()
{
    pid_t child_pid;

    child_pid = clone(childFunc, child_stack + (1024*1024), CLONE_NEWUSER|SIGCHLD, NULL);

    printf("UID outside the namespace %ld\n", (long)geteuid());
    printf("GID outside the namespace %ld\n", (long)getegid());
    waitpid(child_pid, NULL, 0);
    exit(EXIT_SUCCESS);
}