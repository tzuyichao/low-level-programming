#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char linebuf[1024] = {0};
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s [path]", argv[0]);
        return 1;
    }
    if((fp = fopen(argv[1], "r")) == NULL) {
        perror("Can't open file for reading");
        return 1;
    }
    while(fgets(linebuf, sizeof(linebuf), fp) != NULL)
    {
        printf("%s", linebuf);
    }
    fclose(fp);
    return 0;
}