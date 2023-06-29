class Solution {
public:
#define dbg(...) 42;
  vector<vector<int>>pref;
int m, n;
int mod = 1e9 + 7;
vector<vector<vector<int>>>dp;
int dfs(int i, int j, int k) {
  if (k == 0) {
    int sum = pref[m][n] - pref[i][n] - pref[m][j] + pref[i][j];
    return sum > 0;
  }
  if (i >= m || j >= n)return 0;
  int &res = dp[i][j][k];
  if(res != -1) return res;
  res = 0;
  dbg(i, j, k);
  // int res = 0;
  for (int in = i + 1;in < m;in++) {
    int sum = pref[in][n] - pref[in][j] - pref[i][n] + pref[i][j];
    if (sum > 0)res += dfs(in, j, k - 1);
    res %= mod;
  }
  for (int jn = j + 1;jn < n;jn++) {
    int sum = pref[m][jn] - pref[i][jn] - pref[m][j] + pref[i][j];
    if (sum) res += dfs(i, jn, k - 1);
    res %= mod;
  }
  return res;
}

int ways(vector<string>& pizza, int k) {
  m = pizza.size();n = pizza[0].size();
  pref.resize(m + 1, vector<int>(n + 1));
  dp.resize(m,vector<vector<int>>(n,vector<int>(k,-1)));
  for (int i = 1;i <= m;i++) {
    for (int j = 1;j <= n;j++) {
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');
    }
  }
  dbg(pref);
  return dfs(0, 0, k - 1);
}
};