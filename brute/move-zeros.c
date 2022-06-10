int findNZero(int* nums, int numsSize, int pos)
{
    for(int i=pos; i<numsSize; i++) 
        if(nums[i]) return i;
    return -1;
}

void moveZeroes(int* nums, int numsSize)
{
    for(int i=0; i<numsSize; i++) {
        if(nums[i] == 0) {
            int pos = findNZero(nums, numsSize, i+1);
            if(pos != -1) {
                nums[i] = nums[pos];
                nums[pos] = 0;
            } else {
                return;
            }
        }
    }
}