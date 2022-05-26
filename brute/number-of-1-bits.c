// 191. Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/
int hammingWeight(uint32_t n) {
    int res = 0;
    while(n > 0) {
        if(n % 2 == 1) res++;
        n = n >> 1;
    }
    return res;
}