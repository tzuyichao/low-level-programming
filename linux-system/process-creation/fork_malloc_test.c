#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "../common.h"

#define CHILD 		1
#define PARENT		2

#define WORK_ON_MEM(PROCESS, loc, g) do {   \
	if(PROCESS == CHILD) {              \
		loc++; g--;                 \
	} else if(PROCESS == PARENT) {      \
		loc--; g++;                 \
	}                                   \
	printf(" loc=%d, g=%d\n"            \
		" &loc=%p, &g=%p\n"         \
		, loc, g, &loc, &g);        \
} while(0)

const int memsz = 2048;
static char *gptr;
static int g = 5;

static inline void disp_few(char *p)
{
	int i;
	printf("  malloc gptr=%p\n", p);
	for(i=0; i<16; i++)
		printf("%c", *(p+i));
	printf("\n");
}

int main(int argc, char **argv)
{
	pid_t pid;
	int show_vars = 0, loc = 8;
	
	if(argc > 1)
		show_vars = 1;

	gptr = malloc(memsz);
	if(!gptr)
		FATAL("malloc failed!\n");
	printf("Init malloc gptr=%p\n", gptr);
	if(show_vars)
		printf("Init: loc=%d, g=%d\n", loc, g);

	switch((pid = fork())) {
	case -1:
		free(gptr);
		FATAL("fork failed, aborting!\n");
	case 0:
		printf("\nChild processs, PID %d:\n", getpid());
		memset(gptr, 'c', memsz);
		disp_few(gptr);
		if(show_vars)
			WORK_ON_MEM(CHILD, loc, g);
		free(gptr);
		printf("Child %d done, exting...\n", getpid());
		exit(EXIT_SUCCESS);
	default:
#if 1
		sleep(2);
#endif
		printf("\nParent process, PID %d:\n", getpid());
		memset(gptr, 'p', memsz);
		disp_few(gptr);
		if(show_vars)
			WORK_ON_MEM(PARENT, loc, g);
	}

	free(gptr);
	printf("Parent (%d) will exit now...\n", getpid());
	exit(EXIT_SUCCESS);
}
