class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
       // num1 - k * num2 (x) = sum(2^i);
        // setbits(x) <= k
        // x >= k
        for(int k = 0;k<1e7;k++){
            long long x = num1 -1ll * k * num2;
            if(__builtin_popcountll(x) <= k && x >= k){
                return k;
            }
        }
        return -1;
    }
};