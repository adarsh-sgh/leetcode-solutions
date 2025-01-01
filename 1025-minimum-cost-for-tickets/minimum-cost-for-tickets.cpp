class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int inf = 1e9;
        vector<int>dp(n + 1, inf);
        dp[0] = 0;
        for(int i = 0;i<n;i++){
            // dp[i] + 1/7/30 days
            dp[i+1] = min(dp[i+1], dp[i] + costs[0]);

            for(int j = i;j < n && days[j]< days[i] + 7;j++){
                dp[j+1] = min(dp[j+1], dp[i] + costs[1]);
            }

            for(int j = i;j < n && days[j]< days[i] + 30;j++){
                dp[j + 1] = min(dp[j+1], dp[i] + costs[2]);
            }
        }
        // for(auto &x:dp){
        //     cout<<x<<' ';
        // }
        return dp.back();
    }
};