// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int* res = (int*)malloc(2 * sizeof(int));

    int i = 0;
    int j = numbersSize-1;
    while(i < j) {
        int sum = numbers[i] + numbers[j];
        if(sum == target) {
            res[0] = i+1;
            res[1] = j+1;
            break;
        } else if(sum > target) {
            --j;
        } else {
            ++i;
        }
    }
    *returnSize = 2;
    return res;
}