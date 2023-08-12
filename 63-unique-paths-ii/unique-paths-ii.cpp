class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        vector<vector<long long>>dp(m+1,vector<long long>(n+1));
        for(int i = m-1; i>=0 ;i--){
            for(int j = n-1;j >= 0;j--){
                if(g[i][j]==1) {dp[i][j] == 0;continue;}
                if(i + j == m + n - 2) { dp[i][j] = 1;continue;}
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};