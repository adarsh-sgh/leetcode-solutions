class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       // x < 300
    //    dp[i][x] -> longest subsequence ending at i, with min abs diff x or more
        // dp[i][x] = go to all last j such that nums[j] is distinct (300 max)
        // d = abs(nums[i] - nums[j])
        // dp[i][x] = dp[j][d+] or dp[j][d] since d means d or more by defintion (see above)

        //  for each nums[i] last index it appeared on
        map<int,int>mp;
        int n = nums.size();
        int ans = 0;
        vector<vector<int>>dp(n, vector<int>(300, 1));
        for(int i = 0;i< nums.size();i++){
            for(auto &[xj,j]:mp){
                // max 300 iterations (mp.size())
                int d = abs(nums[i] - xj);
                
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                ans = max(ans, dp[i][d]);
                // if(i == 3 && xj == 73){
                //     cout<<dp[j][d]<<" "<<d<<"brr";
                //     cout<<dp[i][d]<<" ";
                // }
            }
            mp[nums[i]] = i;
            // its d only rn, make it d+ in dp[i]
            for(int d = dp[i].size() - 2;d>=0;d--){
                dp[i][d] = max(dp[i][d], dp[i][d+1]);
            }
        }
        return ans;
    }
};

// 24, 12