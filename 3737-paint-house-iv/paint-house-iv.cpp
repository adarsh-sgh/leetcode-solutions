class Solution {
public:
    long long inf = 1e18;
    long long minCost(int n, vector<vector<int>>& cost) {
    //    vector<vector<vector<int>>>dp(n + 1, vector); 
        // vector<array<array<int,3>>, 3>> dp;
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(3,vector<long long>(3)));
        // dp.resize(n);
       // dp[i][x][y] => ith par x and n - i - 1th par y color rakh kar min cost
       // dp[i][x][y] = dp[i-1][xn: !x][yn: !y] + cost[i][xn] + cost[n-i - 1][yn]
       long long ans = inf;
       for(int i = 0;i<n/2;i++){
         for(int x = 0;x < 3;x++){
            for(int y = 0;y < 3;y++){
                dp[i+1][x][y] = inf;
                if(x == y) continue;
                for(int xn = 0;xn < 3;xn++){
                    if(xn == x)continue;
                    for(int yn = 0;yn < 3;yn++){
                        if(xn == yn || y == yn)continue;
                        dp[i+1][x][y] = min(dp[i+1][x][y], dp[i][xn][yn] + cost[i][xn] + cost[n-i-1][yn]);
                        if(i == n/2 - 1){
                            ans = min(ans, dp[i+1][x][y]);
                        }
                    }
                }
            }
         }
       }
        return ans;
    }
};