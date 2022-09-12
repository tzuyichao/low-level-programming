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

static void interpret_wait(pid_t child, int wstatus)
{
	VPRINT("Child (%7d) status changed:\n", child);
	if(WIFEXITED(wstatus))
		VPRINT(" normal termination: exit status: %d\n", WEXITSTATUS(wstatus));
	if(WIFSIGNALED(wstatus)) {
		VPRINT(" abnormal termination: killer signal: %d", WTERMSIG(wstatus));
		if(WCOREDUMP(wstatus))
			VPRINT(" : core dumped\n");
	        else
			VPRINT("\n");
	}
	if(WIFSTOPPED(wstatus))
		VPRINT(" stopped: stop signal: %d\n", WSTOPSIG(wstatus));
	if(WIFCONTINUED(wstatus))
		VPRINT(" (was stopped), resumed (SIGCONT)\n");
}

static char* getcmd(char *cmdstr)
{
	printf("%s", PromptStr);
	fflush(stdout);

	if(!fgets(cmdstr, CMD_MAXLEN - 1, stdin))
		return NULL;
	cmdstr[strlen(cmdstr) - 1] = '\0';
	return cmdstr;
}

static void do_simpsh(void)
{
	pid_t pid, cpid;
	char *cmd;
	int wstat = 0;
	cmd = calloc(CMD_MAXLEN, sizeof(char));
	if(!cmd)
		FATAL("calloc failed!\n");

	while(1) {
		if(!getcmd(cmd)) {
			free(cmd);
			FATAL("calloc failed!\n");
		}
		if(!strncmp(cmd, "quit", 4))
			break;
		if(cmd[0] == 0)
			continue;

		switch((pid = fork())) {
		case -1:
			free(cmd);
			FATAL("fork failed, aborting!\n");
		case 0:
			VPRINT(" Child process (%7d) exec-ing cmd \"%s\" now...", getpid(), cmd);
			if(execlp(cmd, cmd, (char *)0) == -1) {
				WARN("child: execlp failed!\n");
				free(cmd);
				exit(EXIT_FAILURE);
			}
			exit(EXIT_FAILURE);
		default:
			VPRINT("Parent process (%7d) issuing the wait...\n", getpid());
			if((cpid = wait(&wstat)) < 0) {
				free(cmd);
				FATAL("wait failed, aborting...\n");
			}
			if(gVerbose)
				interpret_wait(cpid, wstat);
		}
	}
	free(cmd);
}

static inline void usage(char *name)
{
	printf("Usage: %s [-v]|[--help]\n"
		" -v: verbose mode\n"
		" [TIP: run in verbose mode to see child status change info]\n"
		" --help: display this help screen.\n", name);
}

int main(int argc, char **argv)
{
	if(argc >= 2) {
		if(!strncmp(argv[1], "--help", 6)) {
			usage(argv[0]);
			exit(EXIT_SUCCESS);
		}
		if(!strncmp(argv[1], "-v", 2)) {
			gVerbose = 1;
		}
	}

	do_simpsh();
	VPRINT("Parent process (%7d) exiting...\n", getpid());
	exit(EXIT_SUCCESS);
}
