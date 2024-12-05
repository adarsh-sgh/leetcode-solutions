class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& ss, vector<vector<int>>& ts) {
        // dp[i][j] -> ith node par jth day chhod dein to max kitna kama sakte ho
        // ans  = dp[*][0]  
        // dp[i][j] = max(ss[j][i] + dp[i][j+1], ts[i][a] + dp[a][j+1]); for a -> adj[i]
        vector<vector<int>>dp(n+1,vector<int>(k+1));
        int ans = 0;
        for(int j = k-1;j>=0;j--){
            for(int i = 0;i < n;i++){
                dp[i][j] = ss[j][i] + dp[i][j+1];
                for(int a = 0;a<n;a++){
                 dp[i][j] = max(dp[i][j], ts[i][a] + dp[a][j+1]);
                }
                ans = max(ans, dp[i][0]);
            }
        }
        return ans;
    }
};