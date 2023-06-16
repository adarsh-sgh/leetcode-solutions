class Solution {
public:
    int minimumDeletions(string s) {
  int n = s.size();
  // vector<vector<int>>dp(n + 1, vector<int>(2));
  int dp[n+1][2];
  dp[0][0] = 0;
  dp[0][1] = 0;
  for (int i = 1;i <= n;i++) {
    dp[i][true] = dp[i - 1][true] + (s[i - 1] == 'b');
    dp[i][false] = min(dp[i - 1][true], dp[i - 1][false]) + (s[i - 1] == 'a');
  }
  // dbg(dp)
    return min(dp[n][0], dp[n][1]);
}
};