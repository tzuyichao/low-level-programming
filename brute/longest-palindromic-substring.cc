#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max = 1;

        int start = 0;
        int low = 0;
        int high = 0;
        const int len = s.length();

        for(int i = 1; i<len; i++) {
            low = i - 1;
            high = i;
            while((low >= 0 && high < len) && s[low] == s[high]) {
                if(high - low + 1 > max) {
                    start = low;
                    max = high - low + 1;
                }
                low -= 1;
                high += 1;
            }
            low = i - 1;
            high = i + 1;
            while((low >= 0 && high < len) && s[low] == s[high]) {
                if(high - low + 1 > max) {
                    start = low;
                    max = high - low + 1;
                }
                low -= 1;
                high += 1;
            }
        }

        return s.substr(start, max);
    }
};

/**
 * Runtime: 29 ms, faster than 78.55% of C++ online submissions for Longest Palindromic Substring.
 * Memory Usage: 7 MB, less than 97.86% of C++ online submissions for Longest Palindromic Substring.
 * @brief 
 * 
 * @return int 
 */
int main() {
    auto solver = Solution{};
    auto s1 = string{"babad"};
    cout << solver.longestPalindrome(s1) << endl;
}