/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define dbg(...) 42

class Solution {
public:
    unordered_map<int, vector<int>> adj;
map<int, int> distances;
map<int, bool> vis;
void DFS(TreeNode *root)
{
  if (!root)
    return;

  if (root->left)
  {
    adj[root->val].push_back(root->left->val);
    adj[root->left->val].push_back(root->val);
    DFS(root->left);
  }

  if (root->right)
  {
    adj[root->val].push_back(root->right->val);
    adj[root->right->val].push_back(root->val);
    DFS(root->right);
  }
}

void dfs(int n, int d)
{
  vis[n] = true;
  distances[n] = d;
  for (auto &&it : adj[n])
  {
    if (!vis[it])
    {
      dfs(it, d + 1);
    }
  }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
  DFS(root);
  dfs(target->val, 0);
  vector<int> ans;
  dbg(adj);
  dbg(distances);
  for (auto &&it : distances)
  {
    if (it.second == k)
    {
      ans.push_back(it.first);
    }
  }
  return ans;
}
};