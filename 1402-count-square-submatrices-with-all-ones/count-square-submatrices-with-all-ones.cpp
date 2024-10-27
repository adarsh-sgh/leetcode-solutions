class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

       vector<vector<int>>dp(m+1,vector<int>(n+1)); 
       int ans = 0;
       for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j] = (min({dp[i-1][j], dp[i][j-1],dp[i - 1][j-1]}) + 1) * matrix[i-1][j-1];
            ans += dp[i][j];
        }
       }
       return ans;
    }
};