class Solution {
public:
    #define dbg(...) 42;
     int minOperations(string s1, string s2, int x) {
  vector<int>ind;
  for (int i = 0;i < s1.size();i++) {
    if (s1[i] != s2[i])ind.push_back(i);
  }
  if (ind.size() & 1) return -1;
  vector<int>diff;
  for (int i = 1;i < ind.size();i++) {
    // making these negative 
    int d = ind[i - 1] - ind[i];
    diff.push_back(d);
  }
  int n = diff.size();

  dbg(ind, diff);
  if (n == 0) {
    return ind.size() * x / 2;
  }
  vector<array<int, 2>>dp(n + 1);
  if (-diff[0] < x)dp[1] = { 1,diff[0] };
  for (int i = 2;i <= n;i++) {
    dp[i] = dp[i - 1];
    if (-diff[i - 1] < x) {
      dp[i] = max(dp[i], { dp[i - 2][0] + 1,dp[i - 2][1] + diff[i - 1] });
      dbg(i, dp[i], diff[i - 1])
    }
  }
  dbg(dp);
  auto [cnt, sum] = dp.back();
  sum = -sum;
  dbg(cnt, sum);
  sum += (ind.size() - 2 * cnt) * x / 2;
  return sum;
}
};