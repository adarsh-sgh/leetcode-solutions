class Solution {
public:
#define dbg(...) 42;
    int ID = 2;
map<int, int>sz;
vector<vector<int>>g;
bool oob(int x, int y) {
  return x < 0 || y < 0 || x >= g.size() || y >= g[0].size();
}
vector<int> dir = { -1,0,1,0,-1 };

int dfs(int x, int y, const int id) {
  if (oob(x, y) || g[x][y] != 1)return 0;
  g[x][y] = id;
  int ans = 0;
  for (int d = 0;d < 4;d++) {
    ans += dfs(x + dir[d], y + dir[d + 1], id);
  }
  return ans + 1;
}
int largestIsland(vector<vector<int>>& grid) {
  g = grid;
  for (int i = 0;i < grid.size();i++) {
    for (int j = 0;j < grid[0].size();j++) {
      if (g[i][j] == 1) {
        sz[ID] = dfs(i, j, ID);
        ID++;
      }
    }
  }
  int ans = 0;
  for (int i = 0;i < grid.size();i++) {
    for (int j = 0;j < grid[0].size();j++) {
      if (grid[i][j] == 0) {
        map<int, int>mt;
        for (int d = 0;d < 4;d++) {
          int xn = i + dir[d], yn = j + dir[d + 1];
          if (oob(xn, yn) || g[xn][yn] == 0)continue;
          mt[g[xn][yn]] = sz[g[xn][yn]];
        }
        int curr = 0;
        for (auto&& [x, y] : mt){
          curr+=y;
          }
          ans = max(ans,curr +1);
      }
      else {
        ans = max(ans, sz[g[i][j]]);
      }
    }
  }
  dbg(g, sz);
  return ans;
}
};