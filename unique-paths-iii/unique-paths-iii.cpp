class Solution {
public:
#define dbg(...) 42;
    vector<vector<int>>g;
int m, n;
vector<int>dir{ -1,0,1,0,-1 };
int obs = 0;
int up(int from, int vis) {
  int x = from / n;
  int y = from % n;
  if (g[x][y] == 2) {
    // printBinary(vis);
    // dbg(vis);
    // dbg(bitch, x, y, from, m * n, obs);
    return __builtin_popcount(vis) == m * n - obs;
  }
  dbg(x, y, vis);
  int res = 0;
  for (int d = 0;d < 4;d++) {
    int xn = x + dir[d], yn = y + dir[d + 1];
    int fn = xn * n + yn;
    if (xn < 0 || yn < 0 || xn >= m || yn >= n || vis & (1 << fn) || g[xn][yn] == -1)continue;
    // bitch[xn][yn] = 1;
    res += up(fn, vis | (1 << fn));
  }
  return res;
}

int uniquePathsIII(vector<vector<int>>& grid) {
  int from;
  g = grid;
  m = g.size();
  n = g[0].size();

  for (int i = 0;i < m;i++) {
    for (int j = 0;j < n;j++) {
      if (grid[i][j] == 1) {
        from = i * n + j;
      }
      obs += g[i][j] == -1;
    }
  }
  vector<vector<int>>bitch(m, vector<int>(n));
  bitch[0][0] = 1;
  return up(from, 1 << from);
}
};