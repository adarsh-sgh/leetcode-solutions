class Solution {
public:
    int numMusicPlaylists(int n, int g, int k) {
        vector<vector<long long>>dp(g+1,vector<long long>(n + 1));
        dp[0][0] = 1;
        int mod = 1e9 + 7;
        for(int i = 1;i<=g;i++){
            for(int j = 1;j<=n;j++){
                dp[i][j] = dp[i-1][j-1] * (n-(j-1));
                dp[i][j] += dp[i-1][j] * (max(0,j-k));
                dp[i][j] %=  mod;
            }
        }
        return dp.back().back();
    }
};