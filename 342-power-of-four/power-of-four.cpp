class Solution {
public:
// 1
// 100
// 1 00 00
    bool isPowerOfFour(int n) {
        if(n< 1) return false;
        int n1 = n - 1;
        if(__builtin_popcount(n1) & 1) return false;
        return __builtin_popcount(n) == 1;
    }
};