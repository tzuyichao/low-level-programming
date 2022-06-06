#include <stdio.h>

int digits(int num) 
{
    if(num == 0) return 1;
    int res = 0;
    while(num) {
        ++res;
        num/=10;
    }
    return res;
}

int findNumbers(int* nums, int numsSize)
{
    int res = 0;
    for(int i=0; i<numsSize; i++) {
        int d = digits(nums[i]);
        if(d % 2 == 0) {
            ++res;
        }
    }
    return res;
}

int main()
{
    printf("%d\n", digits(10));
    printf("%d\n", digits(100));
    printf("%d\n", digits(1000));
    printf("%d\n", digits(0));
    printf("%d\n", digits(1));
    return 0;
}