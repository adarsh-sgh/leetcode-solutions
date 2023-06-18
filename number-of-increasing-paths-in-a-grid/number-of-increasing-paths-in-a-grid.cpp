class Solution {
public:
int mod = 1e9+7;
    vector<vector<int>>dp;
int m, n;
vector<vector<int>>g;
bool oob(int i, int j) {
  return  i < 0 || j < 0 || i >= m || j >= n;
}
int cp(int i, int j) {
  if (oob(i, j)) {
    assert(false);
    return 0;
  }
  if (dp[i][j] != -1) return dp[i][j];
  dp[i][j] = 1;
  vector<int>dir{-1, 0, 1, 0, -1};
  for (int d = 0; d < 4;d++) {
    int xn = i + dir[d], yn = j + dir[d + 1];
    if (!oob(xn, yn) && g[xn][yn] < g[i][j]) {
      dp[i][j] += cp(xn, yn);
      dp[i][j]%= mod;
    }
  }
  return dp[i][j];
}
int countPaths(vector<vector<int>>& grid) {
  m = grid.size();
  n = grid[0].size();
  g = grid;
  dp.resize(m, vector<int>(n, -1));
  int ans = 0;
  for (int i = 0;i < m;i++) {
    for (int j = 0; j < n;j++) {
      ans += cp(i, j);
      ans %= mod;
    }
  }
  return ans;
}
};