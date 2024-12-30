class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
       vector<int>dp(high+1);
       dp[0] = 1;
        int mod = 1e9 + 7;
       for(int i = 1;i<=high;i++){
            // put 1 now 
            if(i >= one)dp[i] += dp[i - one];
            // put 0 now 
            if(i >= zero)dp[i] += dp[i - zero];
            dp[i] %= mod;
       }
       for(auto &x:dp)cout<<x<<' ';
       return accumulate(dp.begin() + low, dp.end(), 0ll) % mod;
    }
};