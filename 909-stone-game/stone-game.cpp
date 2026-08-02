class Solution {
public:
// aScore(i,j) = max(p[i] - ascore(i+1,j), p[j] - ascore(i,j-1));
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1));
        for(int i = n - 1;i>=0;i--){
            for(int j = i + 1;j< n;j++){
                if(i == j) dp[i][j] = p[i];
                else dp[i][j]= max(p[i] - dp[i+1][j], p[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};