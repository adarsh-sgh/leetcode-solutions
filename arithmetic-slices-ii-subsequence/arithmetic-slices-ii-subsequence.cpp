class Solution {
public:
   int numberOfArithmeticSlices(vector<int>& nums) {
  int n = nums.size();
  vector<map<long long, long long>>dp(n);
  long long ans = 0;
  for (int i = 0;i < n;i++) {
    for (int j = i - 1;j >= 0;j--) {
      long long d =1ll * nums[i] - nums[j];
      // if (dp[i].count(d))continue;
      if (!dp[j].count(d)) {
        dp[i][d] += 1;
      }
      else {
        // +1 for the 2 length ap
        dp[i][d] += dp[j][d] + 1;
        ans += dp[j][d];
      }
    }
  }
    return ans;
}
};