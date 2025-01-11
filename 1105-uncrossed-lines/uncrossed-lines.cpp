class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       // dp[i][j] -> maxUncrossedLines considering first i el. of nums1 and first j el. of nums2
       // dp[i][j] = dp[i][j-1], dp[i - 1][j], nums1[i] == nums2[j] + dp[i-1][j-1];
         // if i and j both are contributing to ans only option is that they're connected
         int n = nums1.size(), m = nums2.size();
         vector<vector<int>>dp(n+1,vector<int>(m + 1));
         for(int i = 1;i<= n;i++){
            for(int j = 1;j <= m ;j++){
                dp[i][j] =  max({dp[i][j-1], dp[i-1][j], (nums1[i-1] == nums2[j-1]) + dp[i-1][j-1]});
            }
         }
         return dp.back().back();
    }
};