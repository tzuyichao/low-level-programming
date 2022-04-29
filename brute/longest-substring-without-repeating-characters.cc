#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int len = s.length();
        vector<int> count(len, 0);
        for(size_t i=0; i<len; i++) {
            int l = 1;
            vector<int> check(256, 0);
            check[s[i]] = 1;
            count[i] = 1;
            for(size_t j=i+1; j<len; j++) {
                if(check[s[j]] == 1) {
                    count[i] = l;
                    break;
                } else {
                    check[s[j]] = 1;
                    l+=1;
                    count[i] = l;
                }
            } 
        }

        for(int c : count) {
            if(c > res) {
                res = c;
            }
        }

        return res;
    }
};