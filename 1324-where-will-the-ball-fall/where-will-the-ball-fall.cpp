class Solution {
public:
   #define dbg(...) 42;
map<vector<int>, vector<vector<int>>>adj;
int m, n;
vector<vector<vector<int>>>vis;
int bottom(int i, int j, int d) {
  if (i == m) return j;
  if (vis[i][j][d] != -2) return vis[i][j][d];
  vis[i][j][d] = -1;
  for (auto&& x : adj[{i, j, d}]) {
    int b = bottom(x[0], x[1], x[2]);
    if (b != -1) return b;
  }
  return vis[i][j][d] = -1;
}
vector<int> findBall(vector<vector<int>>& grid) {
  m = grid.size();n = grid[0].size();
  for (int i = 0;i < m;i++) {
    for (int j = 0;j < n;j++) {
      adj[{i, j, 1}].push_back({ i,j + 1,3 });
      adj[{i, j + 1, 3}].push_back({ i,j,1 });
      adj[{i, j, 2}].push_back({ i + 1,j,0 });
      if (grid[i][j] == 1) {
        adj[{i, j, 0}].push_back({ i,j,1 });
        adj[{i, j, 3}].push_back({ i,j,2 });
      }
      if (grid[i][j] == -1) {
        adj[{i, j, 0}].push_back({ i,j,3 });
        adj[{i, j, 1}].push_back({ i,j,2 });
      }
    }
  }
  dbg(adj);
  vector<int>ans(n);
     vis.clear();
    vis.resize(m + 1, vector<vector<int>>(n + 1, vector<int>(4, -2)));
  for (int i = 0;i < n;i++) {
 
    ans[i] = bottom(0, i, 0);
  }
  return ans;
}
};