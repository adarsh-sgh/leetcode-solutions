class Solution {
public:
    int mod = 1e9 + 7;
    int numSub(string s) {
       long long ans = 0;
       long long ones = 0;
       for(auto &x:s){
        if(x=='1'){
            ones++;
            ans += ones;
            ans %= mod;
        }else{
            // ans += ones * (ones + 1)/2;
            ones = 0;
        }
       }
       return ans;
    }
};