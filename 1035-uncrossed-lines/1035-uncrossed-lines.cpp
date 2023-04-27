class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
       vector<vector<int>>dp(m + 1,vector<int>(n+1));
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = dp[i+1][j+1] + 1;
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};