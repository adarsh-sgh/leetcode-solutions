class Solution {
public:
    int minInsertions(string s) {
  string sr = s;
  reverse(sr.begin(), sr.end());
  int n = s.size();
  vector<vector<int>>dp(n + 1, vector<int>(n + 1));
  for (int i = n - 1;i >= 0;i--) {
    for (int j = n - 1;j >= 0;j--) {
      if (s[i] == sr[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 1;
      }
      else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  return n - dp[0][0];
}
};