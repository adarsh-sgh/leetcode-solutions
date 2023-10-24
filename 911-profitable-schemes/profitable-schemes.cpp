class Solution {
public:
int mod = 1e9+7;    
vector<int> grp, prof;
int mp;
int dp[102][102][102];
int ps(int i, int p, int m) {
  if (m < 0) return 0;
  if (i == (int)grp.size()) {
    return m >= 0 && p >= mp;
  }
  p = min(p, mp);
  if (dp[i][p][m] != -1) return dp[i][p][m];
    dp[i][p][m] = ps(i + 1, p + prof[i], m - grp[i]) + ps(i + 1, p, m);
    dp[i][p][m] %= mod;
    return dp[i][p][m];
}
int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
  mp = minProfit;
  grp = group;
  prof = profit;
  for (int i = 0;i < 102;i++)
    for (int j = 0;j < 102;j++)
      for (int k = 0;k < 102;k++)
        dp[i][j][k] = -1;
  return ps(0, 0, n);
}

};