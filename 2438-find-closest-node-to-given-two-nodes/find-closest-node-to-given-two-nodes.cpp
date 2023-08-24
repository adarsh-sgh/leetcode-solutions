class Solution {
public:
    void bfs(int node, vector<int>& edges, vector<int>& dis) {
    int n = edges.size();
    vector<int>vis(n);
    queue<int>q;
    q.push(node);
    vis[node] = 1;
    int level = 0;
    while (!q.empty()) {
      int qs = q.size();
      while (qs--) {
        auto x = q.front();
        q.pop();
        dis[x] = level;
        if (edges[x] != -1 && !vis[edges[x]]) {
          vis[edges[x]] = vis[x];
          q.push(edges[x]);
        }
      }
      level++;
    }
  }
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int>vis(n);
    queue<int>q;
    q.push(node1);
    vis[node1] = 1;
    vector<int>dis1(n, INT_MAX), dis2(n, INT_MAX);
    bfs(node1, edges, dis1);
    bfs(node2, edges, dis2);
    int ansi = 0;
    for (int i = 0;i < n;i++) {
      if (max(dis1[i], dis2[i]) < max(dis1[ansi], dis2[ansi])) {
        ansi = i;
      }
    }
    int ans = max(dis1[ansi], dis2[ansi]);
    if (ans >= INT_MAX) return -1;
    return ansi;
  }
};