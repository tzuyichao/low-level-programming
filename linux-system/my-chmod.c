#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void printUsage(FILE *stream, char progname[]);

int main(int argc, char *argv[])
{
    long int accessmode;
    if(argc != 3)
    {
        printUsage(stderr, argv[0]);
        return 1;
    }
    // printf("%d\n", strlen(argv[1]));
    if(strspn(argv[1], "01234567\n") != strlen(argv[1]) || (strlen(argv[1]) != 3 && strlen(argv[1]) != 4))
    {
        printUsage(stderr, argv[0]);
        return 1;
    }
    accessmode = strtol(argv[1], NULL, 8);
    if(chmod(argv[2], accessmode) == -1)
    {
        perror("Can't change permission");
    }

    return 0;
}

void printUsage(FILE *stream, char progname[])
{
    fprintf(stream, "Usage: %s <numeric perission> <path>\n", progname);
}