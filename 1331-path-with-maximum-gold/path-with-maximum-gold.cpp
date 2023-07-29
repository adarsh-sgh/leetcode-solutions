class Solution {
public:
    vector<vector<int>>g;
  vector<int>dir{ -1,0,1,0,-1 };
int gmg(int i, int j) {
  if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || !g[i][j])return 0;
  int gg = 0;
  swap(gg, g[i][j]);
  int res = 0;
  for (int d = 0;d < 4;d++) {
    res = max(res, gg + gmg(i + dir[d], j + dir[d + 1]));
  }
  swap(gg, g[i][j]);
  return res;
}
int getMaximumGold(vector<vector<int>>& grid) {
  g = grid;
  int m = g.size();
  int n = g[0].size();
  int res = 0;
  for (int i = 0;i < m;i++) {
    for (int j = 0;j < n;j++) {
      res = max(res, gmg(i, j));
    }
  }
  return res;
}

};