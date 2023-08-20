class Solution {
public:
   #define dbg(...) 42;
bool hasCycle(int n, vector<vector<int>>& adj, vector<int>& vis) {
  if (vis[n]) return vis[n] == 1;
  vis[n] = 1;
  for (auto&& a : adj[n]) {
    if (hasCycle(a, adj, vis))return true;
  }
  vis[n] = 2;
  return false;
}

void toposort(int n, vector<vector<int>>& adj, vector<int>& vis, vector<int>& order) {
  if (vis[n])return;
  vis[n] = true;
  for (auto&& a : adj[n]) {
    toposort(a, adj, vis, order);
  }
  order.push_back(n);
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
  vector<vector<int>>adj(n + 2 * m);

  for (int g = 0;g < group.size();g++) {
    if (group[g] == -1)continue;
    int gs = n + group[g], ge = n + 2 * m - group[g] - 1;
    adj[gs].push_back(g);
    adj[g].push_back(ge);
  }

  for (int i = 0;i < beforeItems.size();i++) {
    for (auto a : beforeItems[i]) {
      int in = i;
      if (group[i] != group[a]) {
        if (group[i] != -1) {
          in = n + group[i];
        }
        if (group[a] != -1) {
          a = n + 2 * m - group[a] - 1;
        }
      }
      adj[a].push_back(in);
    }
  }

  vector<int>vis(n + 2 * m);
  for (int i = 0;i < n + 2 * m; i++) {
    if (hasCycle(i, adj, vis)) {
      return {};
    }
  }
  for (int i = 0;i < adj.size();i++) {
    dbg(i, adj[i]);
  }
  vis = vector<int>(n + 2 * m);
  vector<int>order;
  for (int i = n + 2 * m - 1;i >= 0; i--) {
    toposort(i, adj, vis, order);
  }
  vector<int>ans;
  dbg(order)
    reverse(order.begin(), order.end());
  for (auto&& o : order) {
    if (o >= n)continue;
    ans.push_back(o);
  }

  return ans;
}
};