#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	printf("Parent PID is %d\n", getpid());
	if((pid = fork()) == -1)
	{
		perror("Can't fork!");
		return 1;
	}
	if(pid == 0) 
	{
		// pid == 0, we are in the child process
		printf("I am the child and will run for 5 minutes. (%d)\n", getpid());
		sleep(300);
		exit(0);
	}
	else if(pid > 0)
	{
		printf("My child PID %d\n I, the parent, will exit when you press enter\n", pid);
		getchar();
		return 0;
	}
	else 
	{
		fprintf(stderr, "Something went wrong forking\n");
		return 1;
	}
	return 0;
}
