#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sigHandler(int sig);

FILE *fp;

const char pidfile[] = "/var/run/my-daemon.pid";

int main(void)
{
	pid_t pid;
	time_t now;
	struct sigaction action;
	const char daemonfile[] = "/tmp/my-daemon-is-alive.txt";
	if((pid = fork()) == -1)
	{
		perror("Can't fork");
		return 1;
	}
	else if(pid != 0)
	{
		exit(0);
	}

	setsid();
	if((pid = fork()) == -1)
	{
		perror("can't fork");
		return 1;
	}
	else if(pid > 0)
	{
		if((fp = fopen(pidfile, "w")) == NULL)
		{
			perror("Can't open file for writing");
			return 1;
		}
		fprintf(fp, "%d\n", pid);
		fclose(fp);
		exit(0);
	}

	umask(022);
	chdir("/");
	if((fp = fopen(daemonfile, "w")) == NULL)
	{
		perror("Can't open darmonfile");
		return 1;
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	open("/dev/null", O_RDONLY); /* 0 = stdin */
	open("/dev/null", O_WRONLY); /* 1 = stdout */
	open("/dev/null", O_RDWR); /* 2 = stderr */

	action.sa_handler = sigHandler;
	sigfillset(&action.sa_mask);
	action.sa_flags = SA_RESTART;

	sigaction(SIGTERM, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGABRT, &action, NULL);

	for(;;)
	{
		time(&now);
		fprintf(fp, "Daemon alive at %s", ctime(&now));
		fflush(fp);
		sleep(30);
	}
	return 0;
}

void sigHandler(int sig)
{
	int status = 0;
	if(sig == SIGTERM || sig == SIGINT || sig == SIGQUIT || sig == SIGABRT)
	{
		if((unlink(pidfile)) == -1)
			status = 1;
		if((fclose(fp)) == EOF)
			status = 1;
		exit(status);
	}
	else 
	{
		exit(1);
	}
}

