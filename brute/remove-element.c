

int removeElement(int* nums, int numsSize, int val)
{
    if(numsSize == 0)
        return 0;
    int r = 0;
    int l = numsSize-1;
    while(r <= l) {
        if(nums[l] == val) {
            --l;
            continue;
        }
        if(nums[r] == val) {
            nums[r] = nums[l];
            ++r;
            --l;
        } else {
            ++r;
        }
    }
    return l+1;
}