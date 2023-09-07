class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](auto a, auto b) {
        return a[1] < b[1];
         });
         vector<int>v1(n);
        for(int i = 0;i<n;i++)v1[i] = events[i][1];
        vector<vector<int>>dp(n+1,vector<int>(k+1));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j <= k;j++){
                // int ip = i;
                auto ip = lower_bound(v1.begin(),v1.begin() + i-1,events[i-1][0]) - v1.begin();
                // while(ip && events[ip-1][1] >= events[i-1][0])ip--;
                dp[i][j] = max(dp[i-1][j],events[i-1][2] + dp[ip][j-1]);
            }
        }
        return *max_element(dp[n].begin(),dp[n].end());
    }
};