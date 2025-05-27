class Solution {
public:
    int differenceOfSums(int n, int m) {
       int sum1 = 0, sum2 = 0;
       for(int i = 1;i <= n;i++)sum1 += i * (i % m != 0 ),sum2 += i * (i % m == 0);
       return sum1 - sum2;
    }
};