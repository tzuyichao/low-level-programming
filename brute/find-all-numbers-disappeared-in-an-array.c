

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int db[numsSize+1];
    for(int i=1; i<numsSize+1; i++)
        db[i] = -1;
    for(int i=0; i<numsSize; i++)
        db[nums[i]] = 1;
    int c = 0;
    for(int i=1; i<numsSize+1; i++)
        if(db[i] == -1) ++c;
    int* res = (int*)malloc(c*sizeof(int));
    int idx=0;
    for(int i=1; i<numsSize+1; i++) {
        if(db[i] == -1) {
            res[idx++] = i;
        }
    }
    *returnSize = c;
    return res;
}