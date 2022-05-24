#include <stdio.h>

void showmsg(char * msg) {
    printf("%s\n", msg);
}

int main(int argc, char **argv) {
    char szMsg[] = "Hello, world!";
    showmsg(szMsg);

    return 0;
}