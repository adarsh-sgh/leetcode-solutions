class Solution {
public:
    long long coloredCells(int n) {
       // 1, 4, 12 
       return 1ll + 2ll * n * (n - 1);
    //    return 1 - n  + 2 * n * (n + 1);
    }
};