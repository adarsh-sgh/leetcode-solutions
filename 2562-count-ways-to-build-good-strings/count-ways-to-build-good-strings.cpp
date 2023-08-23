class Solution {
public:
    int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int z, int o) {
        vector<vector<long long>>dp(high + 1, vector<long long>(2));
        dp[0][0] = 1;
        long long ans = 0;
        for(int i = 1;i<=high;i++){
            if(i-z>=0) dp[i][0] = dp[i-z][0] + dp[i-z][1];
            if(i-o>=0) dp[i][1] = dp[i-o][0] + dp[i-o][1];
            dp[i][0] %= mod;
            dp[i][1] %= mod;
            if(i>= low && i <= high){
                ans += dp[i][0] + dp[i][1];
                ans %= mod;
            }
            
        }
        return ans;

    }
};