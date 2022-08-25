#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include "../common.h"

static void siggy(int signum)
{
	const char *str1 = "*** siggy: handled SIGINT ***\n";
	const char *str2 = "*** siggy: handled SIGQUIT ***\n";

	switch(signum) {
	case SIGINT:
		if(write(STDOUT_FILENO, str1, strlen(str1)) < 0)
			WARN("write str1 failed!");
		return;
	case SIGQUIT:
		if(write(STDOUT_FILENO, str2, strlen(str2)) < 0)
			WARN("write str2 failed!");
		return;
	}
}

int main(void)
{
	unsigned long int i = 1;
	struct sigaction act;
	memset(&act, 0, sizeof(act));
	act.sa_handler = siggy;
	if(sigaction(SIGINT, &act, 0) < 0)
		FATAL("sigaction on SIGINT failed!");
	printf("Running pid: %d\n", getpid());
	while(1) {
		printf("Looping, iteration #%02ld ...\n", i++);
		(void)sleep(1);
	}
	exit(EXIT_SUCCESS);
}

