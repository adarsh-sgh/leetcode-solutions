class Solution {
public:
#define dbg(...) 42;
int mod = 1e9 + 7;
    int kInversePairs(int n, int k) {
  vector<vector<long long>>dp(n + 1, vector<long long>(k + 1));
  for (auto& x : dp[0])x = 1;
  for (int i = 1;i <= n;i++) {
    dp[i][0] = 1;
    for (int j = 1;j <= k;j++) {
      auto& x = dp[i][j];
      x = dp[i][j - 1];
        x %= mod;
        x += dp[i - 1][j];
        x %= mod;
        if (j - i >= 0)x = x + mod - dp[i - 1][j - i];
        x %= mod;
      dbg(i, j, x)

    }
  }
//   cout << dp;
  return (mod + dp[n][k] - (k ? dp[n][k - 1] : 0)) % mod;
}
};