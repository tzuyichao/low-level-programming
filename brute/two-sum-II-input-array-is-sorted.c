// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int* res = (int*)malloc(2 * sizeof(int));

    for(int i=0; i<numbersSize; i++) {
        for(int j=0; j<numbersSize; j++) {
            if(i != j && numbers[i] + numbers[j] == target) {
                if(i>j) {
                    res[0] = j+1;
                    res[1] = i+1;
                } else {
                    res[0] = i+1;
                    res[1] = j+1;
                }
                break;
            } 
        }
    }
    *returnSize = 2;
    return res;
}