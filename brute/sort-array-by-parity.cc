#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;
        vector<int> odd;
        for(auto num : nums) {
            if(num % 2 == 0) {
                res.push_back(num);
            } else {
                odd.push_back(num);
            }
        }
        res.insert(res.end(), odd.begin(), odd.end());
        return res;
    }
};

/**
 * 905. Sort Array By Parity
 * 
 * Runtime: 13 ms, faster than 56.05% of C++ online submissions for Sort Array By Parity.
 * Memory Usage: 16.8 MB, less than 7.27% of C++ online submissions for Sort Array By Parity.
 * 
 * @brief 
 * 
 * @return int 
 */
int main() {

}