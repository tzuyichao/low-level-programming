#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	if(fork() == -1)
	{
		perror("fork failed!");
		return 1;
	}
	printf("Hello, fork.\n");
	return 0;
}
