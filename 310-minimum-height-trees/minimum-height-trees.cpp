class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
  vector<vector<int>>adj(n);
  vector<int>degree(n);
  for (auto&& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
    degree[e[0]]++;
    degree[e[1]]++;
  }
  queue<int>leaf;
  vector<int>vis(n);
  for (int i = 0;i < n;i++) {
    if (adj[i].size() <= 1) {
      leaf.push(i);
      vis[i] = true;
    }
  }
  queue<int>lastLeaf;
  while (leaf.size()) {
    int n = leaf.size();
     lastLeaf = leaf;
    while (n--) {
      auto t = leaf.front();
      leaf.pop();
      for (auto&& a : adj[t]) {
        // if (vis[a])continue;
        degree[a]--;
        // vis[a] = true;
        if(degree[a]==1)leaf.push(a);
      }
    }
  }
  vector<int>ans;
  while (lastLeaf.size()) {
    ans.push_back(lastLeaf.front());
    lastLeaf.pop();
  }
  return ans;
}
};