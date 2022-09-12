#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static void bar(unsigned int nsec)
{
	printf(" %s:%s :: will take a nap for %us ...\n", __FILE__, __func__, nsec);
	sleep(nsec);
}

static void foo(unsigned int nsec)
{
	printf(" %s:%s :: will take a nap for %us ...\n", __FILE__, __func__, nsec);
	sleep(nsec);
}

int main(int argc, char **argv)
{
	pid_t ret;
	if(argc != 3) 
	{
		fprintf(stderr, "Usage: %s {child-alive-sec} {parent-alive-sec}\n", argv[0]);
		return 1;
	}

	switch((ret = fork()))
	{
		case -1:
			perror("fork failed, aborting!");
			return 1;
		case 0:
			printf("Child process, PID %d:\n"
					"return %d from frok()\n", getpid(), ret);
			foo(atoi(argv[1]));
			printf("Child process (%d) done, exiting...\n", getpid());
			return 0;
		default:
			printf("Parent process, PID %d:\n"
					"return %d from fork()\n", getpid(), ret);
			bar(atoi(argv[2]));
	}
	printf("Parent (%d) will exit now...\n", getpid());
	return 0;
}
