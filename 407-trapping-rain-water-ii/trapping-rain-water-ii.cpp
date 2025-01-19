class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
  int m = heightMap.size(), n = heightMap[0].size();
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>q;
  vector<vector<int>>vis(m, vector<int>(n));
  for (int i = 0;i < m;i++) {
    q.push({ heightMap[i][0],i,0 });
    q.push({ heightMap[i][n - 1],i,n - 1 });
    vis[i][0] = vis[i][n - 1] = true;
  }
  for (int j = 1;j < n - 1;j++) {
    q.push({ heightMap[0][j],0,j });
    q.push({ heightMap[m - 1][j],m - 1,j });
    vis[0][j] = vis[m - 1][j] = true;
  }
  auto oob = [&](int x, int y) {
    return x < 0 || y < 0 || x >= m || y >= n;
  };
  vector<int> d = { -1,0,1,0,-1 };
  int ans = 0;
  while (!q.empty()) {
    auto t = q.top();q.pop();
    int h = t[0], x = t[1], y = t[2];
    for (int i = 0;i < 4;i++) {
      int xn = x + d[i], yn = y + d[i + 1];
      if (oob(xn, yn) || vis[xn][yn]) continue;
      vis[xn][yn] = true;
      if (heightMap[xn][yn] < h) {
        ans += h - heightMap[xn][yn];
        heightMap[xn][yn] = h;
      }
      q.push({ heightMap[xn][yn],xn,yn });
    }
  }
  return ans;
}
};