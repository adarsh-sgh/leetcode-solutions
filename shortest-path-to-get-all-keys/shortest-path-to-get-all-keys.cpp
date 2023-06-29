class Solution {
public:
#define dbg(...) 42;

int shortestPathAllKeys(vector<string>& grid){
  char highestKey = 'a';
  int m = grid.size();
  int n = grid[0].size();
  pair<int, int>start;
  // start i , j -> keys -> nextKey
  vector<vector<map<int, map<char, vector<int>>>>>memo(m, vector<map<int, map<char, vector<int>>>>(n));
  for (int i = 0;i < m;i++) {
    for (int j = 0;j < n;j++) {
      if (grid[i][j] > 'a' && grid[i][j] <= 'f') {
        highestKey = max(highestKey, grid[i][j]);
      }
      if (grid[i][j] == '@') {
        start = { i,j };
      }
    }
  }
  string keys = "";
  for (int c = 'a';c <= highestKey;c++) {
    keys += c;
  }
  dbg(keys);
  int ans = INT_MAX;
  auto startOrig = start;
  while (true) {
    start = startOrig;
    int curr = 0;
    unsigned int keysFound = 0;
    for (int i = 0;i < keys.size();i++) {
      auto& xd = memo[start.first][start.second][keysFound];
      if (xd.count(keys[i])) {
        // xd[keys[i]] = {0,0,0};
        curr += xd[keys[i]][0];
        if (curr > 1e5)break;
        keysFound |= (1 << (keys[i] - 'a'));
        start = { xd[keys[i]][1],xd[keys[i]][2] };
        continue;
      }
      auto& lmao = xd[keys[i]];
      lmao = {0,0,0};
      //distance to reach keyi from start
      vector<vector<int>>vis(m, vector<int>(n));
      queue<pair<int, int>>q;
      q.push(start);
      vis[start.first][start.second] = true;
      int dis = 0;int keyDist = 1e6;
      while (!q.empty()) {
        int qsz = q.size();
        while (qsz--) {
          auto [x, y] = q.front();q.pop();
          // dbg(x, y);
          if (grid[x][y] == keys[i]) {
            queue<pair<int, int>>temp;
            swap(q, temp);
            // curr += dis;
            keyDist = dis;
            start = { x,y };
            lmao[1] = x;
            lmao[2] = y;
            dbg(x, y, dis);
            break;
          }
          vector<int>dir = { -1,0,1,0,-1 };
          for (int d = 0;d < 4;d++) {
            int xn = x + dir[d], yn = y + dir[d + 1];
            // dbg(xn, yn, m, n);
            if (xn < 0 || yn < 0 || xn >= m || yn >= n)continue;
            // dbg(xn, yn, grid[xn][yn], vis[xn][yn]);
            if (vis[xn][yn] || grid[xn][yn] == '#')continue;
            // dbg(xn, yn);
            if (grid[xn][yn] >= 'A' && grid[xn][yn] <= 'F' && !(keysFound & (1 << (grid[xn][yn] - 'A')))) continue;
            // {
            //   bool found = false;
            //   for (int z = 0;z < i;z++) {
            //     if (grid[xn][yn] + 'a' - 'A' == keys[z]) { found = true;break; }
            //   }
            //   if (!found)continue;
            // }
            // dbg(xn, yn);

            vis[xn][yn] = true;
            q.push({ xn,yn });
          }
        }
        dis++;
      }
      lmao[0] = keyDist;
      curr += lmao[0];
      if (lmao[0] > 1e5)break;
      keysFound |= (1 << (keys[i] - 'a'));
    }
    dbg(keys, curr);
    ans = min(ans, curr);
    if (!next_permutation(keys.begin(), keys.end())) break;
  }
  if (ans > 1e3) return -1;
  return ans;
}
};