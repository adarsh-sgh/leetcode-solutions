class Solution {
public:
    int minimumDeletions(string s) {
  int n = s.size();
  vector<vector<int>>dp(n + 1, vector<int>(2));
  for (int i = 1;i <= n;i++) {
    dp[i][true] = dp[i - 1][true] + (s[i - 1] == 'b');
    dp[i][false] = min(dp[i - 1][true], dp[i - 1][false]) + (s[i - 1] == 'a');
  }
  // dbg(dp)
    return min(dp.back()[0], dp.back()[1]);
}
};