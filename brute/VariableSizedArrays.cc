#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    int q;
    scanf("%d %d\n", &n, &q);
    vector<int> data[n];
    for(int i=0; i<n; i++) {
        int num;
        scanf("%d", &num);
        for(int j=0; j<num; j++) {
            int val;
            scanf("%d", &val);
            data[i].push_back(val);
        }
    }
    vector<int> res;
    for(int i=0; i<q; i++) {
        int row;
        int col;
        scanf("%d %d", &row, &col);
        res.push_back(data[row][col]);
    }
    for(int i=0; i<q; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}