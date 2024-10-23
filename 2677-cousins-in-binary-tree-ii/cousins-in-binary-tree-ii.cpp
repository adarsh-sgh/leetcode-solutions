/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    #define dbg(...) 42;
  vector<int> levelSum;
void replace(TreeNode* r, int level) {
  if (!r) return;
  int sumChild = (r->left ? r->left->val : 0) + (r->right ? r->right->val : 0);
  if (r->left) {
    r->left->val = levelSum[level + 1] - sumChild;
    replace(r->left, level + 1);
  }
  if (r->right) {
    r->right->val = levelSum[level + 1] - sumChild;
    replace(r->right, level + 1);
  }
}
TreeNode* replaceValueInTree(TreeNode* root) {
  queue<TreeNode* > q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    int sum = 0;
    while (n--) {
      auto x = q.front();
      q.pop();
      sum += x->val;

      if (x->left) q.push(x->left);
      if (x->right) q.push(x->right);
    }
    levelSum.push_back(sum);
  }
  dbg(levelSum);
  replace(root, 0);
  root->val = 0;
  return root;
}
};