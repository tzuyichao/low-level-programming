#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define MAXSIZE 4096

int main(int argc, char *argv[])
{
    int fd;
    int maxread;
    off_t filesize;
    struct stat fileinfo;
    char rbuf[MAXSIZE] = {0};
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s [path]\n", argv[0]);
        return 1;
    }
    if((fd = open(argv[1], O_RDONLY)) == -1)
    {
        perror("Can't open file");
        return 1;
    }
    fstat(fd, &fileinfo);
    filesize = fileinfo.st_size;
    if(filesize >= MAXSIZE)
        maxread = MAXSIZE - 1;
    else
        maxread = filesize;
    if((read(fd, rbuf, maxread)) == -1)
    {
        perror("Can't read file");
        return 1;
    }
    printf("%s", rbuf);
    return 0;
}