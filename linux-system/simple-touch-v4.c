#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <linux/limits.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char filename[PATH_MAX] = {0};
    if(argc != 2)
    {
        fprintf(stderr, "You must supply a filename as an argument\n");
        return 1;
    }
    strncpy(filename, argv[1], PATH_MAX-1);
    if(creat(filename, 00644) == -1)
    {
        fprintf(stderr, "Can't create file %s\n", filename);
        if(errno == EACCES)
        {
            fprintf(stderr, "Permission Denied\n");
        }
        else if(errno == ENOENT)
        {
            fprintf(stderr, "Parent directories does not exist\n");
        } 
        else
        {
            fprintf(stderr, "Unknown Error\n");
        }
        return 1;
    }

    return 0;
}