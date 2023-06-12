class Solution {
public:
   vector<vector<int>>g1, g2;
vector<int>dir{-1, 0, 1, 0, -1};
// int cnt = 0;
void flood(int x, int y) {
  if (x < 0 || y < 0 || x >= g1.size() || y >= g1[0].size() || !g2[x][y]) {
    return;
  }
  // cnt++;
  g2[x][y] = 0;
  for (int d = 0;d < 4;d++) {
    int xn = x + dir[d], yn = y + dir[d + 1];
    flood(xn, yn);
  }
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
  g1 = grid1;
  g2 = grid2;
  for (int i = 0;i < grid1.size();i++) {
    for (int j = 0;j < g1[0].size();j++) {
      if (!g1[i][j])flood(i, j);
    }
  }
  // dbg(cnt);
  // cnt = 0;
  // cout << g2;
  int cnt = 0;
  for (int i = 0;i < grid1.size();i++) {
    for (int j = 0;j < g1[0].size();j++) {
      if (g2[i][j]) {
        cnt++;
        flood(i, j);
      }
    }
  }
  // cout << g2;
  return cnt;
}
};