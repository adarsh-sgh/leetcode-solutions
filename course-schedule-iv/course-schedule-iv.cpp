class Solution {
public:
  vector<vector<int>>adj;
vector<int>vis;
bool dfs(int i, const int target) {
  if (i == target) return true;
  if (vis[i]) return false;
  vis[i] = true;
  for (auto&& x : adj[i]) {
    if (dfs(x, target))return true;
  }
  return false;
}
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
  adj.resize(numCourses);
  vis.resize(numCourses);
  for (auto p : prerequisites) {
    adj[p[0]].push_back(p[1]);
  }
  vector<bool>ans;
  for (auto&& q : queries) {
    int x = q[0], y = q[1];
    ans.push_back(dfs(x, y));
    vis.clear();
    vis.resize(numCourses);
  }
  return ans;
}
};