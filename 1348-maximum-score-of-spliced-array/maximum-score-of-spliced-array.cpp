class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>>v = {nums1,nums2};
        //index, array, transitions
        vector<array<array<int,3>,2>>dp(n+1);
        for(int i = 1;i<=n;i++){
            for(int a = 0;a<2;a++){
                dp[i][a][0] = dp[i-1][a][0] + v[a][i-1];
                dp[i][a][1] = max(dp[i-1][a][1] + v[a][i-1], dp[i-1][!a][0] + v[!a][i-1]);
                dp[i][a][2] = max(dp[i-1][a][2] + v[a][i-1], dp[i-1][!a][1] + v[!a][i-1]);
            }
        }
        //dp[n] ka max
        int ans = 0;
        for(auto &x:dp[n]){
            for(auto &y:x){
                ans=max(ans,y);
            }
        }
        return ans;
    }
};