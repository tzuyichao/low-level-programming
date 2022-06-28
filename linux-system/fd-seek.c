#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#define MAXSIZE 4096

int main(int argc, char *argv[])
{
    int fd;
    int maxread;
    off_t filesize;
    struct stat fileinfo;
    char rbuf[MAXSIZE] = {0};
    if(argc < 3 || argc > 4)
    {
        fprintf(stderr, "Usage: %s [path] [from pos] [byte to read]\n", argv[0]);
        return 1;
    }
    if((fd = open(argv[1], O_RDONLY)) == -1)
    {
        perror("Can't open file for reading");
        return 1;
    }
    fstat(fd, &fileinfo);
    filesize = fileinfo.st_size;

    if(filesize >= MAXSIZE)
    {
        maxread = MAXSIZE - 1;
    }
    else if(argv[3] != NULL)
    {
        if(atoi(argv[3]) >= MAXSIZE)
        {
            fprintf(stderr, "To big size specfied\n");
            return 1;
        }
        maxread = atoi(argv[3]);
    }
    else
    {
        maxread = filesize;
    }
    lseek(fd, atoi(argv[2]), SEEK_SET);
    if((read(fd, rbuf, maxread)) == -1)
    {
        perror("Can't read file");
        return 1;
    }
    printf("%s\n", rbuf);
    return 0;
}