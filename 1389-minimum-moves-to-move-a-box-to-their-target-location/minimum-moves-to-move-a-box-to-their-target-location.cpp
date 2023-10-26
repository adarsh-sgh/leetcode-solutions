class Solution {
public:
    #define dbg(...) 42;
    int minPushBox(vector<vector<char>>& grid) {
  auto isAdj = [](int x, int y, int a, int b) {
    return abs(a - x) + abs(y - b) == 1;
    };
  vector<int>dir = { -1,0,1,0,-1 };
  deque<array<int, 5>>q;
  array<int, 5>start;
  array<int, 2>target;
  int n = grid.size(), m = grid[0].size();
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < m;j++) {
      if (grid[i][j] == 'S') {
        start[0] = i, start[1] = j;
      }
      else if (grid[i][j] == 'B') {
        start[2] = i;start[3] = j;
      }
      else if (grid[i][j] == 'T') {
        target = { i,j };
      }
    }
  }
  int vis[21][21][21][21];
  memset(vis, 0, sizeof(vis));
  for (int i = 0;i < 21;i++) {
    for (int j = 0;j < 21;j++) {
      for (int k = 0;k < 21;k++) {
        for (int l = 0;l < 21;l++) {
          assert(vis[i][j][k][l] == 0);
        }
      }
    }
  }
  q.push_back(start);
  auto [_x, _y, _z, _w, _i] = start;
  vis[_x][_y][_z][_w] = true;
  auto oob = [&](int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' ;
    };
  while (q.size()) {
    auto [t1, t2, t3, t4, t5] = q.front();
    // assert({t1,t2} != {t3,t4});
    q.pop_front();
    dbg(t1, t2, t3, t4, t5, target);
    if (t3 == target[0] && t4 == target[1]) return t5;
    if (isAdj(t1, t2, t3, t4)) {
      int xn = 2 * t3 - t1, yn = 2 * t4 - t2;
      dbg(xn, yn);
      if (!oob(xn, yn) && !vis[t3][t4][xn][yn]) {
        vis[t3][t4][xn][yn] = true;
        q.push_back({ t3,t4,xn,yn,t5 + 1 });
      }
    }
    for (int d = 0;d < 4;d++) {
      int xn = t1 + dir[d], yn = t2 + dir[d + 1];
      if(xn==t3 && yn==t4)continue;
      if (oob(xn, yn) || vis[xn][yn][t3][t4])continue;
      vis[xn][yn][t3][t4] = true;
      q.push_front({ xn,yn,t3,t4,t5 });
    }
  }
  return -1;

}
};