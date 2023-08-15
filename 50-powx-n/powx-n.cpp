class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0) return 1;
        if(n<0){
            x = 1/x;

            n = -n;
        }
        double p = myPow(x,n/2);
        double res = p *p;
        if(n&1) res *= x;
        return res;
    }
};