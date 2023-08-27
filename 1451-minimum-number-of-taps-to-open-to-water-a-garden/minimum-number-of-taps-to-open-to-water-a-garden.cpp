class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
  int inf = 1e9;
  vector<int>dp(n + 1, inf);
  dp[0] = 0;
  for (int i = 0;i < ranges.size();i++) {
    int prev = 0;
    if (i - ranges[i] > 0)prev = dp[i - ranges[i]];
    for (int j = max(i - ranges[i],0);j <= i + ranges[i] && j <= n;j++) {
      dp[j] = min(dp[j], prev + 1);
    }
  }
  return dp[n] == inf ? -1 : dp[n];
}
};