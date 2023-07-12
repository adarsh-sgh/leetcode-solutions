class Solution {
public:
   vector<int> sfe;
vector<vector<int>> adj;
vector<int> vis;
bool safe(int n)
{
  if (sfe[n] != -1)
    return sfe[n];
  if (vis[n] == 1){
    sfe[n] = 1;
    return true;
    }
  vis[n] = 1;
  for (auto &&x : adj[n])
  {
    if (safe(x)){
      sfe[n] = 1;
      return true;}
  }
  vis[n] = 2;
  sfe[n] = 0;
  return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
  int n = graph.size();
  sfe.resize(n, -1);
  vis.resize(n, 0);
  // adj.resize(n);
  adj = graph;
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    if (!safe(i))
      ans.push_back(i);
  }
  return ans;
}
};