class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
       int n = grid.size(), m = grid[0].size(); 
       int dp[101][101][202] = {};
       // omc = open - closed brackets in this path
       dp[0][1][0] = dp[1][0][0] = 1;
       for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int k = 0;k<201;k++){
                int curr = grid[i-1][j-1] == '(' ? -1 : 1;
                // if(i==3 && j == 3 && k == 1){
                //     cout<<curr<<"curr, dp->"<<dp[i][j-1][k+curr];
                // }
                if(k + curr >= 0)dp[i][j][k] = dp[i-1][j][k+curr] || dp[i][j-1][k+curr];
            }
        }
       }
    //    cout<<dp[1][1][1]<<' '<<dp[2][2][1]<<' '<<dp[3][2][2]<<' '<<dp[3][3][1];
       return dp[n][m][0];
    }
};