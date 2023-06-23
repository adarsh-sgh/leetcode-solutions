class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        vector<vector<int>>dp(1001,vector<int>(1000));
        int mx = 2;
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
                int d = nums[j] - nums[i] + 500;
                dp[d][j] = max(dp[d][i] +1,2);
                mx = max(mx,dp[d][j]);
            }
        }
        return mx;
    }
};