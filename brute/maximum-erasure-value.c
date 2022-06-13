int max(int a, int b) {
    return a > b?a:b;
}

int maximumUniqueSubarray(int* nums, int numsSize){
    int s[10001] = {0};
    int res = 0;
    for(int l=0, r=0, sum=0; r<numsSize; r++) {
        while(s[nums[r]] == 1 && l < r) {
            sum -= nums[l];
            s[nums[l++]] = 0;
        }
        s[nums[r]] = 1;
        sum += nums[r];
        res = max(res, sum);
    }

    return res;
}