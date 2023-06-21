class Solution {
public:
    vector<vector<int>>adj;
int n;
string s;
int ans = 0;
int dfs(int n) {
  int res = 0;
  int mx = 1;
  priority_queue<int>q;
  for (auto&& a : adj[n]) {
    int x = dfs(a);
    if (s[a] != s[n]) {
      q.push(x);
    }
    // mx = max(mx, 1);
  }
  int x1 = 0, x2 = 0;
  if (q.size()) { x1 = q.top();q.pop(); }
  if (q.size()) x2 = q.top();
  ans = max(ans, x1 + x2 + 1);
  return max(x1, x2) + 1;
}
int longestPath(vector<int>& parent, string S) {
  n = parent.size();
  adj.resize(n);
  for (int i = 1;i < n;i++) {
    adj[parent[i]].push_back(i);
  }
  s = S;
  // dbg(adj)
    dfs(0);
  return ans;
}
};