class Solution {
public:

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        int inf = 1e9+1;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        function<int(int,int)> f=[&](int ind,int rem){
            if(rem == 0) return 0;
            if(ind == n) return inf;
            if(dp[ind][rem] != -1) return dp[ind][rem];
            int take,notake;
            take=cost[ind]+f(ind+1,max(0,rem-time[ind]-1));
            notake=f(ind+1,rem);

            return dp[ind][rem] = min(take,notake);
        };
        return f(0,n);
    }
};