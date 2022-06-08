int cmpFunc(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int removeDuplicates(int* nums, int numsSize)
{
    int cur = nums[0];
    int d = 0;
    for(int i=1; i<numsSize; i++) {
        if(nums[i] == cur) {
            nums[i] = 101;
            ++d;
        } else {
            cur = nums[i];
        }
    }
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    return numsSize-d;
}