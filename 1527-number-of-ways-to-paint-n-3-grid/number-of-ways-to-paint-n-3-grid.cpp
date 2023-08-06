class Solution {
public:
    int numOfWays(int n) {
        vector<vector<long long>>dp(n+1,vector<long long>(2,0));
        int mod = 1e9 + 7;
        dp[1][0] = 6;
        dp[1][1] = 6;
        for(int i = 2;i<=n;i++){
            dp[i][0] = 2 *(dp[i-1][0] + dp[i-1][1]);
            dp[i][1] = 2*dp[i-1][0] + 3 * dp[i-1][1];
            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }
        return (dp.back()[0] + dp.back()[1])%mod;
    }
};