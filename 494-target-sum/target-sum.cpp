class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int n = nums.size();
       vector<vector<int>>dp(n+1,vector<int>(2002));
       auto vt = [&](int x){
        return x >= 0 && x < 2002;
       };
      dp[0][0 + 1000] = 1;
       for(int i = 0;i<n;i++){
        for(int t = -1000;t<=1000;t++){
            dp[i+1][t + 1000] = 
            //    dp[i][t + 1000]+
               (vt(t + 1000 - nums[i]) ? dp[i][t + 1000 - nums[i]] : 0) +
               (vt(t + 1000 + nums[i])? dp[i][t + 1000 + nums[i]]: 0);
        }
       }
       return dp[n][target + 1000];
    }
};