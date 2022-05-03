#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int h = 0;
        int t = n-1;
        while(h < n) {
            if(nums[h] != sorted[h]) {
                break;
            }
            h++;
        }
        while(t >= 0) {
            if(nums[t] != sorted[t]) {
                break;
            }
            t--;
        }
        int res = t - h + 1;
        return res > 0?res:0;
    }
};

/**
 * 581. Shortest Unsorted Continuous Subarray
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 *
 * Runtime: 46 ms, faster than 42.79% of C++ online submissions for Shortest Unsorted Continuous Subarray.
 * Memory Usage: 27.5 MB, less than 32.44% of C++ online submissions for Shortest Unsorted Continuous Subarray.
 * 
 * @brief 
 * 
 */
int main() {

}