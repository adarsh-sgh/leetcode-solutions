class Solution {
public:
   vector<vector<int>>g;
int n;
bool possible(int time) {
  queue<pair<int, int>>q;
  if(g[0][0]>time) return false;
  q.push({ 0,0 });
  vector<vector<int>>vis(n, vector<int>(n));
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    if (t.first == n - 1 && t.second == n - 1) return true;
    vector<int>dir = { -1,0,1,0,-1 };
    for (int d = 0;d < 4;d++) {
      int xn = t.first + dir[d], yn = t.second + dir[d + 1];
      if (xn < 0 || xn >= n || yn < 0 || yn >= n || vis[xn][yn] || g[xn][yn] >time) continue;
      vis[xn][yn] = true;
      q.push({ xn,yn });
    }
  }
  return false;
}

int swimInWater(vector<vector<int>>& grid) {
  g = grid;
  n = g.size();
  int l = 0, r = n * n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (possible(mid)) {
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }
  return l;
  // for (int t = 0;t < n * n;t++) {
  //   if (possible(t)) return t;
  // }
  // return n*n;
}
};