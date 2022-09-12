#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	fork();
	printf("\n(%d) Hello, fork.\n", getpid());
	return 0;
}
