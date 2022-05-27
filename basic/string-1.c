#include <stdio.h>

char *a() {
	char *p = "hello world";
	return p;
}

int main() {
	char *b = a();
	printf("%s\n", b);
}
