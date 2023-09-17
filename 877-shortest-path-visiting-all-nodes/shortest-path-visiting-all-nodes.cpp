class Solution {
public:
// if node n is already visited with mask m
  vector<map<int,bool>>vis;
  int shortestPathLength(vector<vector<int>>& graph) {
  int n = graph.size();
  vis.resize(n);
  // queue -> node, mask, distance
  queue<vector<int>>q;
  for (int i = 0;i < n;i++) {
    q.push({ i,(1 << i),0 });
  }
  while (!q.empty()) {
    vector<int> v = q.front();
    q.pop();
    int x = v[0], m = v[1], d = v[2];
    if(vis[x][m])continue;
    vis[x][m] = true;
    if (m == ((1 << n) - 1)) {
      return d;
    }
    for (auto y : graph[x]) {
      q.push({ y,m | (1 << y),d + 1 });
    }
  }
  assert(false);
  return -1;
}
};