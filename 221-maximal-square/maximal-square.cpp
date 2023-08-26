class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>dp(m + 1,vector<int>(n + 1));
        dp[0][0] = 0;
        int maxl = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]=='0')continue;
                dp[i+1][j+1] = 1 + min({dp[i][j],dp[i+1][j],dp[i][j+1]});
                maxl = max(maxl, dp[i+1][j+1]);
            }
        }
        return maxl * maxl;
    }
};