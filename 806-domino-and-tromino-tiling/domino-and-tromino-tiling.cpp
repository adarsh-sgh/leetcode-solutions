class Solution {
public:
    int mod = 1e9 + 7;
    int numTilings(int n) {
        if(n<2){
            return n != 0;
        }
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<=n;i++){
            dp[i] = (2 * dp[i-1]) % mod + dp[i-3];
            dp[i] %= mod;
        }
        return dp[n];
    }
};