class Solution {
public:
    int mod = 1e9 + 7;
    int numSub(string s) {
       long long ans = 0;
       long long ones = 0;
       for(auto &x:s){
        if(x=='1'){
            ones++;
        }else{
            ans += ones * (ones + 1)/2;
            ans %= mod;
            ones = 0;
        }
       }
       ans += ones * (ones + 1)/2;
       ans %= mod;
       return ans;
    }
};