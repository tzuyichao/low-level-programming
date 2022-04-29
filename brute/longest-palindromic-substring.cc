#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        size_t max = 1;

        size_t start = 0;
        size_t low = 0;
        size_t high = 0;
        size_t len = s.length();

        for(size_t i = 1; i<len; i++) {
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

int main() {
    auto solver = Solution{};
    auto s1 = string{"babad"};
    cout << solver.longestPalindrome(s1) << endl;
}