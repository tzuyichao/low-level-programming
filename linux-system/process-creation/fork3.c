#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	if(fork() == -1)
	{
		perror("fork failed!");
		return 1;
	}
	printf("PID %d: Hello, fork\n", getpid());
	return 0;
}
