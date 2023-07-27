class Solution {
public:

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
  vector<vector<vector<int>>>adj(2, vector<vector<int>>(n));
  for (auto&& e : redEdges) {
    adj[0][e[0]].push_back(e[1]);
    // adj[0][e[1]].push_back(e[0]);
  }
  for (auto&& e : blueEdges) {
    adj[1][e[0]].push_back(e[1]);
    // adj[1][e[1]].push_back(e[0]);
  }
  vector<int>ans(n, 1e4);
  for (int z = 0;z < 2;z++) {
    queue<int>q;
    q.push(0);
    int dis = 0;
    vector<vector<int>>vis(n,vector<int>(2,false));
    ans[0] = 0;
    bool color = z;
    vis[0][color] = true;

    while (q.size()) {
      int qs = q.size();
      while (qs--) {
        auto t = q.front();
        q.pop();
        for (auto&& a : adj[color][t]) {
          if (vis[a][color])continue;
          vis[a][color] = true;
          ans[a] = min(ans[a], dis + 1);
          q.push(a);
        }
      }
      dis++;
      color = !color;
    }

  }
  for (auto&& x : ans) {
    if (x >= 1e4)x = -1;
  }
  return ans;

}
};