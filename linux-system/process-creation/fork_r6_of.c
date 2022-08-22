#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../common.h"

#define CHILD		1
#define PARENT		2

const int seekto = 10, lnsize = 80, numlines = 100;

static void work_on_file(int whom, int fd)
{
	char *buf = calloc(lnsize, sizeof(char));
	int i;
	
	if(!buf)
		FATAL("malloc failed\n");
	printf(" in %s:%s now...\n", __FILE__, __func__);
	if(whom == CHILD) {
		printf("    context: child process (%d)\n", getpid());
		if(lseek(fd, seekto, SEEK_SET) < 0) {
			free(buf);
			close(fd);
			FATAL("child: lseek failed\n");
		}
		memset(buf, 'c', lnsize-1);
		buf[lnsize-1] = '\n';
		for(i=0; i<numlines; i++) {
			if(write(fd, buf, lnsize) == -1) {
				free(buf);
				close(fd);
				FATAL("child: write failed\n");
			}
		}
	} else if (whom == PARENT) {
		printf("    context: parent process (%d)\n", getpid());
		if(lseek(fd, seekto + (lnsize*numlines), SEEK_SET) < 0) {
                        free(buf);
                        close(fd);
                        FATAL("parent: lseek failed\n");
                }
                memset(buf, 'p', lnsize-1);
                buf[lnsize-1] = '\n';
                for(i=0; i<numlines; i++) {
                        if(write(fd, buf, lnsize) == -1) {
                                free(buf);
                                close(fd);
                                FATAL("parent: write failed\n");
                        }
                }
	}
	free(buf);
}

static void do_work(int fd)
{
	pid_t pid;
	switch((pid = fork())) {
		case -1:
			FATAL("fork failed, aborting\n");
		case 0:
			printf("Child process, PID %d:\n", getpid());
			work_on_file(CHILD, fd);
			close(fd);
			printf("Child (%d) done, exiting...\n", getpid());
			exit(EXIT_SUCCESS);
		default:
#if 0
			sleep(1);
#endif
			printf("Parent process, PID %d:\n", getpid());
			work_on_file(PARENT, fd);
			close(fd);
	}
}

int main(int argc, char **argv)
{
	int fd;
	if(argc != 2) {
		fprintf(stderr, "Usage: %s {test-file-name}\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	unlink(argv[1]);

#define FILEMODE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
	fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, FILEMODE);
	if(fd == -1)
		FATAL("open (%s) failed\n", argv[1]);
	do_work(fd);
	printf("Parent (%d will exit now...\n", getpid());
	exit(EXIT_SUCCESS);
}
