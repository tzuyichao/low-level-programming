#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<int> p(10);
    iota(begin(p), end(p), 0);
    for(auto v: p) {
        cout << v << endl;
    }
}