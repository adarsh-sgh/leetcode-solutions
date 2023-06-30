class Solution {
public:
#define dbg(...) 42;
vector<vector<int>>dis;
int inf = 1e6;
int minCost(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  dis = vector<vector<int>>(m, vector<int>(n, inf));
  dis[0][0] = 0;
  deque<pair<int, int>>q;
  q.push_back({ 0,0 });
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop_front();
    vector<pair<int, int>>dir = {
      {0,1},
      {0,-1},
      {1,0},
      {-1,0}
    };
    for (int i = 0;i < 4;i++) {
      int xn = x + dir[i].first;
      int yn = y + dir[i].second;
      if (xn < 0 || yn < 0 || xn >= m || yn >= n || dis[xn][yn] < dis[x][y] + 1)continue;
      if (i + 1 == grid[x][y]) {
        q.push_front({ xn,yn });
        dis[xn][yn] = dis[x][y];
      }
      else {
        dis[xn][yn] = dis[x][y] + 1;
        q.push_back({ xn,yn });
      }
    }

  }
  dbg(dis);
  return dis[m - 1][n - 1];
}
};