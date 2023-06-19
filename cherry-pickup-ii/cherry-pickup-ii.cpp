class Solution {
public:
vector<vector<vector<int>>>dp;
int m, n;
bool oob(vector<int> v) {
  for (auto it : v)
    if (it < 0) return true;
  return v[0] >= m || v[1] >= n || v[2] >= n;
}
vector<vector<int>>g;
int cp(int row, int c1, int c2) {
  // dbg(row, c1, c2)
    if (oob({ row,c1,c2 })|| c1 > c2) return 0;
  if (dp[row][c1][c2] != -1) return dp[row][c1][c2];
  int res = 0;
  for (int d = -1;d <= 1;d++) {
    for (int d2 = -1;d2 <= 1;d2++) {
      res = max(res, cp(row + 1, c1 + d, c2 + d2));
    }
  }
  res += g[row][c1];
  if (c1 != c2) res += g[row][c2];

  return dp[row][c1][c2] = res;
}

int cherryPickup(vector<vector<int>>& grid) {
  m = grid.size();
  n = grid[0].size();
  g = grid;
  dp.resize(m, vector<vector<int>>(n, vector<int>(n, -1)));
  return cp(0, 0, n - 1);
}
};