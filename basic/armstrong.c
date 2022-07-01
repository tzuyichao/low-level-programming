#include <stdio.h>
#include <math.h>

#define MAX 10

int top=-1;
int stack[MAX];
void push(int);
int pop();
int findarmstrong(int);

// gcc /mnt/c/GitHub/low-level-programming/basic/armstrong.c -lm -o armstrong
int main()
{
    int n;
    printf("Enter a number ");
    scanf("%d", &n);
    if(findarmstrong(n))
    {
        printf("%d is an armstrong number", n);
    }
    else 
    {
        printf("%d is not an armstrong number", n);
    }
    return 0;
}

int findarmstrong(int num)
{
    int j, rem, temp, count, value;
    temp = num;
    count = 0;
    while(num > 0)
    {
        rem = num % 10;
        push(rem);
        count++;
        num = num/10;
    }
    num = temp;
    value = 0;
    while(top >= 0)
    {
        j = pop();
        value = value + pow(j, count);
    }
    if(value = num) return 1;
    else return 0;
}

void push(int m)
{
    top++;
    stack[top] = m;
}

int pop()
{
    int j;
    if(top == -1) 
        return top;
    else 
    {
        j = stack[top];
        top--;
        return j;
    }
}