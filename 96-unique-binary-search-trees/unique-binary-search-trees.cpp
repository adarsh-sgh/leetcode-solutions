class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(20);
        dp[0] = 1;
        for(int s = 1;s<n+1;s++){
            for(int s1 = 0;s1<s;s1++){
                dp[s] += dp[s1] * dp[s - s1 - 1];
            }
        }
        return dp[n];
    }
};