#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int res = 0;
    int count = 0;
    for(int i=0; i<numsSize; i++) {
        if(nums[i] == 1) {
            ++count;
        } else {
            if(count > res) {
                res = count;
            }
            count = 0;
        }
    }
    if(count > res) {
        res = count;
    }
    return res;
}

int main() 
{
    int nums[] = {1, 1, 0, 1, 1, 1};
    printf("%d\n", findMaxConsecutiveOnes(nums, 6));
    return 0;
}