#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../common.h"

#define CMD_MAXLEN	128

static int gVerbose = 0;
const char *PromptStr = ">> ";

static char *getcmd(char *cmdstr)
{
	printf("%s", PromptStr);
	fflush(stdout);

	if(!fgets(cmdstr, CMD_MAXLEN-1, stdin))
		return NULL;

	cmdstr[strlen(cmdstr)-1] = '\0';
	return cmdstr;
}

static void do_simpsh(void)
{
	pid_t pid;
	char *cmd;

	cmd = calloc(CMD_MAXLEN, sizeof(char));
	if(!cmd)
		FATAL("calloc failed!\n");

	while(1) {
		if(!getcmd(cmd)) {
			free(cmd);
			FATAL("getcmd(): EOF or failed\n");
		}
		if(!strncmp(cmd, "quit", 4))
			break;

		switch((pid = fork())) {
		case -1:
			free(cmd);
			FATAL("fork failed, aborting!\n");
		case 0:
			VPRINT(" Child process (%7d) exec-ing cmd \"%s\" now...\n", getpid(), cmd);
			if(execlp(cmd, cmd, (char *)0) == -1) {
				WARN("child: execlp failed\n");
				free(cmd);
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		default:
			VPRINT("Parent process (%7d) issuing the wait...\n", getpid());
			if(wait(0) < 0)
				FATAL("wait failed, aborting...\n");
		}
	}
	free(cmd);
}

static inline void usage(char *name)
{
	printf("Usage: %s [-v]|[--help]\n"
		" -v: verbose mode\n"
		" --help: display this help screen.\n", name);
}

int main(int argc, char **argv)
{
	if(argc >= 2) {
		if(!strncmp(argv[1], "--help", 6)) {
			usage(argv[0]);
			exit(EXIT_SUCCESS);
		}
		if(!strncmp(argv[1], "-v", 2))
			gVerbose = 1;
	}

	do_simpsh();
	VPRINT("Parent process (%7d) exiting...\n", getpid());
	exit(EXIT_SUCCESS);
}
