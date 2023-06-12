class Solution {
public:
#define dbg(...) 42;
   double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
  vector<vector<pair<double, int>>>adj(n);
  for (int i = 0;i < edges.size();i++) {
    auto e = edges[i];
    adj[e[0]].push_back({ succProb[i],e[1] });
    adj[e[1]].push_back({ succProb[i],e[0] });
  }

  vector<double>prob(n, 0);
  prob[start] = 1;
  vector<int>vis(n);
  priority_queue<pair<double, int>>q;
  q.push({ 1,start });
  // vis[start] = true;
  for (int i = 0;i < n-1 ;i++) {
    if (q.empty())break;
    // assert(q.size());
    auto [pr, node] = q.top();
    dbg(pr, node)
      q.pop();
    if (vis[node])continue;
    vis[node] = true;

    for (auto&& [x, y] : adj[node]) {
        if(x*pr > prob[y]){
            prob[y] = x*pr;
            q.push({prob[y],y});
        }
    }
  }
  dbg(prob)
    return prob[end];
}
};