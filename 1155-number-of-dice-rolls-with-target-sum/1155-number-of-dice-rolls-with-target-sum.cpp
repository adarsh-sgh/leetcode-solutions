class Solution {
public:
    vector<vector<int>>dp;
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1,vector<int>(target+1,-1));
        return numRollsToTarget2( n,  k,  target);
    }
    int mod = 1e9 + 7;
    int numRollsToTarget2(int n, int k, int target) {
        
        if(n * k < target || n > target) return 0;
        if(n == 0 && target == 0) return 1;
        if(dp[n][target] != -1) return dp[n][target];
        int ways = 0;
        for(int i =1;i<=k;i++){
            ways += numRollsToTarget2(n-1,k,target-i) % mod;
            ways %= mod;
        }
        dp[n][target] = ways;
        return ways;
    }
};