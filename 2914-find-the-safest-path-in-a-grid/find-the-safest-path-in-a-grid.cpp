class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
  vector<vector<int>>vis(grid.size(), vector<int>(grid.size()));
  queue<pair<int, int>>q;

  for (int i = 0;i < grid.size();i++) {
    for (int j = 0;j < grid[0].size();j++) {
      if (grid[i][j]) {
        q.push({ i,j });
        grid[i][j] = 0;
      }
      else {
        grid[i][j] = -1;
      }
    }
  }
  auto oob = [&](int x, int y) {
    return x < 0 || y < 0 || x >= grid.size() || y >= grid.size();
    };
  vector<int>dir{ -1,0,1,0,-1 };
  int level = 1;
  while (q.size()) {
    int qn = q.size();
    while (qn--) {
      auto [x, y] = q.front();
      q.pop();
      for (int d = 0;d < 4;d++) {
        int xn = x + dir[d], yn = y + dir[d + 1];
        if (xn < 0 || yn < 0 || xn >= grid.size() || yn >= grid[0].size() || grid[xn][yn] != -1)continue;
        grid[xn][yn] = level;
        q.push({ xn,yn });
      }
    }
    level++;
  }

  priority_queue<vector<int>>pq;
  pq.push({ grid[0][0],0,0 });
  level = 1;
  int minsafe = 1e6;
  while (pq.size()) {
    int qn = pq.size();
    while (qn--) {
      auto t = pq.top();
      pq.pop();
      int x = t[1], y = t[2];
      minsafe = min(minsafe, grid[x][y]);
      if (x == grid.size() - 1 && y == grid.size() - 1) return minsafe;
      for (int d = 0;d < 4;d++) {
        int xn = x + dir[d], yn = y + dir[d + 1];
        if (oob(xn, yn) || vis[xn][yn])continue;
        vis[xn][yn] = 1;
        pq.push({ grid[xn][yn],xn,yn });
      }
    }
  }
  assert(false);
  return -1;
}
};