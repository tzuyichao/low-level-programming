#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "../common.h"

int main(int argc, char **argv)
{
	pid_t ret;

	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s {child-numbtyes-to-write} {parent-numbytes-to-write}\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	switch((ret = fork()))
	{
		case -1:
			FATAL("fork failed, aborting!");
		case 0:
			printf("Child process, PID %d:\n"
					" return %d from fork()\n", getpid(), ret);
			DELAY_LOOP('c', atoi(argv[1]));
			printf("Child process (%d) done, exiting...\n", getpid());
			exit(EXIT_SUCCESS);
		default:
			printf("Parent process, PID %d:\n"
					" return %d from fork()\n", getpid(), ret);
			DELAY_LOOP('p', atoi(argv[2]));
	}
	printf("Parent (%d) will exit now...\n", getpid());
	exit(EXIT_SUCCESS);
}
