#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack{{'*', 0}};
        for(char c: s) {
            if(c != stack.back().first) {
                stack.push_back({c, 1});
            } else if(++stack.back().second == k) {
                stack.pop_back();
            }
        }
        string res;
        for(const auto& p: stack) {
            res.append(p.second, p.first);
        }
        return res;
    }
};

// ref: https://zxi.mytechroad.com/blog/stack/leetcode-1209-remove-all-adjacent-duplicates-in-string-ii/
int main() {
    Solution solver;
    string str{"abcd"};
    auto k = 2;
    cout << str << " removeDuplicates with k=" << k << " is " << solver.removeDuplicates(str, k) << endl;
}