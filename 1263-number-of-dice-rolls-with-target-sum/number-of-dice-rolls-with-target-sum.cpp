class Solution {
public:
    vector<vector<int>>dp;
    int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        // dp.resize(n+1,vector<int>(target+1,-1));
        dp.resize(31,vector<int>(1001));
        dp[0][0] = 1;
        for(int i = 1;i<31;i++){
            for(int t = 0;t<1001;t++){
                for(int x = 1;x<=k;x++){
                    if(t-x >= 0){
                        dp[i][t]+= dp[i-1][t-x];
                        dp[i][t] %= mod;
                        }
                }
            }
        }
        return dp[n][target];
        // return numRollsToTarget2( n,  k,  target);
    }

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