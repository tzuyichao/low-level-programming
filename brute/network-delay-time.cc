#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        constexpr int MAX_TIME = 101 * 100;
        vector<int> dist(n, MAX_TIME);
        dist[k - 1] = 0;
        for (int i = 1; i < n; ++i)
            for (const auto& time : times) {
                int u = time[0] - 1, v = time[1] - 1, w = time[2];
                dist[v] = min(dist[v], dist[u] + w);
            }
        int max_dist = *max_element(dist.begin(), dist.end());
        return max_dist == MAX_TIME ? -1 : max_dist;
    }
};

int main() {
    Solution solver;

    cout << "Done." << endl;
}