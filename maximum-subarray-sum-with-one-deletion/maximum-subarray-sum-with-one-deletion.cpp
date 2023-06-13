class Solution {
public:
#define dbg(...) 42;
#define ll long long
   vector<vector<ll>>dp;
int n;
vector<int>nums;
int ms(int i, bool canJump) {
  if (i < 0) return 0;
  if (dp[i][canJump] > INT_MIN) return dp[i][canJump];
  if (canJump) {
    int c1 = ms(i - 1, true);
    int c2 = ms(i - 2, false);
    if (c2 >= c1) {
      return dp[i][canJump] = max(nums[i] + c2, nums[i]);
    }
    return dp[i][canJump] = max(nums[i] + c1, nums[i]);
  }
  return dp[i][canJump] = max(nums[i] + ms(i - 1, false), nums[i]);
}
int maximumSum(vector<int>& arr) {
  n = arr.size();
  dp.resize(n, vector<ll>{INT_MIN, INT_MIN});
  nums = arr;
  int ans = ms(n - 1, true);
  dbg(dp);
  for (int i = 0;i < n;i++) {
    ans = max({ 1ll * ans,dp[i][0],dp[i][1] });
  }
  return ans;
}
};