class Solution {
public:
  vector<vector<char>>grid;
vector<int>dir{ -1,0,1,0,-1 };
bool oob(int x, int y) {
  return x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size();
}
bool dfs(int x, int y, int px, int py) {
  if (oob(x, y))return false;
  if (px != -1 && grid[x][y] == grid[px][py])return true;
  if(grid[x][y]<'a') return false;
  grid[x][y] += 'A' - 'a';
  for (int d = 0;d < 4;d++) {
    int xn = x + dir[d], yn = y + dir[d + 1];
    if(oob(xn,yn)||xn==px && yn==py)continue;
    if(grid[xn][yn]!=grid[x][y] + 'a' - 'A' && grid[xn][yn] != grid[x][y])continue;

    if (dfs(xn, yn, x, y)) return true;
  }
  return false;
}
bool containsCycle(vector<vector<char>>& g) {
  grid = g;
  for (int i = 0;i < g.size();i++) {
    for (int j = 0;j < g[0].size();j++) {
      if (grid[i][j] <= 'Z')continue;
      if (dfs(i, j, -1, -1) == true) return true;
    }
  }
  return false;
}
};