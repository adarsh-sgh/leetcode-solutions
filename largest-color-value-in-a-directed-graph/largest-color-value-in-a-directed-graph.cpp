class Solution {
public:
#define dbg(...) 42;
   map<int, vector<int>>m;
vector<vector<int>>adj;
string col;
vector<int>pvs(int n) {
  if (m.count(n)) return m[n];
  m[n].resize(26);
  m[n][col[n] - 'a']++;
  for (auto&& x : adj[n]) {
    auto temp = pvs(x);
    for (int i = 0;i < 26;i++) {
      m[n][i] = max(temp[i] + (i == col[n] - 'a'), m[n][i]);
    }
  }
  return m[n];
}

vector<int>vis;
bool hasLoop(int n) {
  //1 -> node is exited 
  if (vis[n] != 0) return vis[n] == 2;
  vis[n] = 2;
  for (auto&& x : adj[n]) {
    if (hasLoop(x))return true;
  }
  vis[n] = 1;
  return false;
}
int largestPathValue(string colors, vector<vector<int>>& edges) {
  int n = colors.size();
  vis.resize(n);
  col = colors;
  adj.resize(n);
  for (auto&& x : edges) {
    auto a = x[0], b = x[1];
    adj[a].push_back(b);
  }

  for (int i = 0;i < n;i++) {
    if (hasLoop(i)) return -1;
  }
  int ans = 0;
  for (int i = 0;i < n;i++) {
    auto v = pvs(i);
    for (auto&& x : v) {
      ans = max(x, ans);
    }
  }
  for (auto&& [x, y] : m) {
    dbg(x, y);
  }
  return ans;
}
};