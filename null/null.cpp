class Solution {
public:
    double myPow(double x, long long n) {
        if(n<0){
            x = 1/x;
            n = -n;
        }
        if(n==0) return 1;
        double p = myPow(x,n/2);
        if(n&1) return p*p*x;
        return p*p;
    }
};