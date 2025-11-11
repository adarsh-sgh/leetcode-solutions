class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sn = strs.size();
        // vector<vector<vector<int>>>(sn+1, vector<int>(m, vector<int>(n));
        vector<vector<vector<int>>>dp(sn+1, vector<vector<int>>(m+1, vector<int>(n+1)));
        vector<array<int,2>>v;
        for(auto &s:strs){
            v.push_back({0,0});
            for(auto &c:s){
                int x = c - '0';
                v.back()[x]++;
            }
        }
        for(int i = 1;i< sn+1;i++){
           for(int j = 0;j<=m;j++){
            for(int k = 0;k <= n;k++){
                // i str consider karke
                // max j 0 and k 1 use karke
                // kitna bada ban sakta hai 
                if(j) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                if(k) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                int ix = j- v[i-1][0];
                int iy = k - v[i-1][1];
                if(ix >= 0 && iy >= 0)dp[i][j][k] = max(dp[i][j][k],1 + dp[i-1][ix][iy]);
            }
           } 
        }
        return dp.back().back().back();
    }
};

// for str[i] only cnt0 and cnt1 matters
// cnt0 = [1, 3, 2, 0, 1]
// cnt1 = [1, 1, 4, 1, 0]

//dp[i][m][n] = 

// 600 * 1e4