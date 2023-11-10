class Solution {
public:
#define dbg(...) 42;
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
  vector<long long>dp(n);
  vector<vector<int>>adj(n);
  for (auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }
  function<void(int, int)> dfs1 = [&](int node, int parent)->void {
    dp[node] = price[node];
    for (auto& a : adj[node]) {
      if (a == parent)continue;
      dfs1(a, node);
      dp[node] = max(dp[node], price[node] + dp[a]);
    }
    };
  dfs1(0, -1);
  dbg(dp);

  function<void(int, int, int)>dfs2 = [&](int node, int parent, int pc)->void {
    multiset<long long>se;
    se.insert(pc + price[node]);
    for (auto& a : adj[node]) {
      if (a == parent)continue;
      se.insert(price[node] + dp[a]);
      if (se.size() > 2)se.erase(se.begin());
    }
    dbg(node, se);
    for (auto& a : adj[node]) {
      if (a == parent)continue;
      auto bk = *se.rbegin(), st = *se.begin();
      if (dp[a] == bk - price[node]) {
        dp[a] = max(dp[a], st + price[a]);
        dfs2(a, node, st);
      }
      else {
        dp[a] = max(dp[a], bk + price[a]);
        dfs2(a, node, bk);
      }
    }
    };
  dfs2(0, -1, 0);
  long long ans = 0;
  for (int i = 0;i < n;i++) {
    ans = max(ans, dp[i] - price[i]);
  }
  dbg(dp);
  return ans;
}
};