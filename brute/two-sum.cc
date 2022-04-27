class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, 0);
        map<int, int> memo;
        for(size_t i=0; i<nums.size(); ++i) {
            int r = target-nums[i];
            auto iter = memo.find(nums[i]);
            if(iter != memo.end()) {
                res[0] = i;
                res[1] = iter->second;
                return res;
            } else {
                memo[r] = i;
            }
        }
        return res;
    }
};
