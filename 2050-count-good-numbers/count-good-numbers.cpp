class Solution {
public:
    int mod = 1e9 + 7;
    long long binExp(long long x,long long n){
        // break n by 2 in each step
        if(n == 0) return 1;
        int b2 = binExp(x, n/2);
        return (n % 2 ? x : 1)* b2 * b2 % mod;
    }

    int countGoodNumbers(long long n) {
        if(n == 1) return 5;
        // prime numbers = 2, 3, 5, 7, 
        // even = 0, 2 ...8 => 5
        long long oi = n / 2;
        long long ei = (n+1)/2;
        return binExp(4, oi) * binExp(5, ei) % mod;
        // n = 4, oi = 2, ei = 2 
    }
};