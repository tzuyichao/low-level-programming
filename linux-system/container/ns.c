#define _GNU_SOURCE
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>


/**
 * source: 左耳朵耗子
 * https://coolshell.cn/articles/17010.html
 */

#define STACK_SIZE (1024*1024)
static char container_stack[STACK_SIZE];

char* const container_args[] = {
    "/bin/bash",
    NULL
};

int container_main(void* arg)
{
    printf("Container - inside the container!\n");
    execv(container_args[0], container_args);
    printf("Something wrong!");
    return 1;
}

int main()
{
    printf("Parent - start a container!\n");
    int container_pid = clone(container_main, container_stack+STACK_SIZE, CLONE_NEWNS | SIGCHLD, NULL);
    printf("Parent - container pid: %d\n", container_pid);
    waitpid(container_pid, NULL, 0);
    printf("Parent - container stoped.\n");
    return 0;
}