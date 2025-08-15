class Solution {
public:
    bool isPowerOfFour(int n) {
       long long x = 1;
       if(n == 1) return true;
       while(x < n){
        x *= 4;
        if(x == n) return true;
       }
       return false; 
    }
};