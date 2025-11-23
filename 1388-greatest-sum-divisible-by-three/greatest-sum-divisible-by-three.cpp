class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[i][j] => i elements ka sum that gives remainder j when %3
        int n = nums.size();
        vector<array<int, 3>> dp(n+1);  
        dp[0][1] = dp[0][2] = -1e8;
        for (int i = 0; i < n; i++) {
                // dp[i][0]
                // 0 -> 0
                // 1 -> 2
                // 2 -> 1
                // dp[i][1]
                // 0 -> 1
                // 1 -> 0
                // 2 -> 2

                // dp[i][2]
                // 0 2
                // 2 0
                // 1 1
                dp[i+1] = dp[i];
                int r = nums[i] % 3;
                int j1 = (3 - r) % 3;
                dp[i + 1][0] = max(dp[i+1][0],dp[i][j1]+ nums[i]);

                int j2 = r == 2? 2: (1 - r);
                dp[i+1][1] = max(dp[i+1][1],dp[i][j2]+ nums[i]);

                int j3 = r == 1?1:2-r;
                dp[i+1][2] = max(dp[i+1][2],dp[i][j3]+ nums[i]);

                // a subseq starting now
                dp[i+1][r] = max(dp[i+1][r], nums[i]);
        }
        return dp.back()[0];
    }
};