class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,1e9+1));
        // dp(i,rem) --> ith index tak rem bachane ke liye min cost

        // base case
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=n;j++){
                int take,notake;
                notake=dp[i+1][j];
                take=cost[i]+dp[i+1][max(0,j-time[i]-1)];

                dp[i][j]=min(take,notake);
            }
        }
        return dp[0][n] ;

    }
};