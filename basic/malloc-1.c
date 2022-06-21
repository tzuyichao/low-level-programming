#include <stdio.h>
#include <stdlib.h>

typedef struct value {
    struct value* vals;
    int val;
} Value;

int main()
{
    Value* values = (Value*) malloc(10 * sizeof(Value));

    if(values == NULL) {
        printf("values is null");
    } else {
        printf("values is not null");
        if(values[0].vals) {
            printf("values[0].vals is not null");
        } else {
            printf("values[0].vals is null");
        }
    }

    free(values);
    return 0;
}