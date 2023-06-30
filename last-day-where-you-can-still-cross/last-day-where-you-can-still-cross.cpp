class Solution {
public:
#define dbg(...) 42;
   vector<vector<int>>g;

vector<int>dir{ -1,0,1,0,-1 };
vector<vector<int>>vis;

bool dfs(int x, int y, const int day) {
  dbg(x, y, day, g.size());
  if (x >= (int)g.size()) {
    return true;
  }
  dbg(x, y, day, vis[x][y]);
  if (x < 0 || y < 0 || x >= (int)g.size() || y >= (int)g[0].size() || g[x][y] <= day || vis[x][y])return false;
  dbg(x, y, vis[x][y])
    vis[x][y] = true;
  dbg(x, y, day);
  for (int d = 0;d < 4;d++) {
    if (dfs(x + dir[d], y + dir[d + 1], day))return true;
  }
  return false;
}

int canReach(int day) {
  vis.clear();
  vis.resize(g.size(), vector<int>(g[0].size()));
  for (int j = 0;j < g[0].size();j++) {
    if (dfs(0, j, day))return true;
  }
  return false;
}

int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
  g.clear();
  g.resize(m, vector<int>(n));
  for (int i = 0;i < cells.size();i++) {
    g[cells[i][0] - 1][cells[i][1] - 1] = i + 1;
  }
  // cout << g;
  int l = 0, r = cells.size();
  // return dfs(0, 0, 0);
  while (l < r) {
    dbg(l, r);
    int mid = (l + r + 1) / 2;

    if (canReach(mid)) {
      l = mid;
    }
    else {
      r = mid - 1;
    }
  }
  return l;
}
};