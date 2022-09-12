#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "../common.h"

static int g = 7;

int main(int argc, char **argv)
{
	pid_t pid;
	int loc = 8;

	switch((pid = fork())) {
		case -1:
			FATAL("fork failed, aborting!\n");
		case 0:
			printf("Child process, PID %d:\n", getpid());
			loc++;
			g--;
			printf(" loc=%d g=%d\n", loc, g);
			printf("Child (%d) done, exiting...\n", getpid());
			exit(EXIT_SUCCESS);
		default:
// After the fork, the order of execution between the parent and child process is indeterminate.
#if 1
			sleep(2);
#endif
			printf("Parent process, PID %d:\n", getpid());
			loc--;
			g++;
			printf(" loc=%d g=%d\n", loc, g);
	}
	printf("Parent (%d) will exit now...\n", getpid());
	exit(EXIT_SUCCESS);
}
