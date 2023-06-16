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
 
bool isEvenOddTree(TreeNode* root) {
  queue<TreeNode*>q;
  q.push(root);
  int level = 0;
  while (q.size()) {
    int n = q.size();
    int prev = (level & 1) ? INT_MAX : -1;
    while (n--) {
      auto t = q.front();
      q.pop();
      // dbg(t->val, prev, level);
if ((t->val - prev) * ((level & 1) ? -1 : 1) <= 0) {
        // dbg(t->val, prev, level)
          return false;
      }
      if (!((level & 1) ^ (t->val & 1))) {
        // dbg(t->val, prev, level);
        return false;
      }
      prev = t->val;
      if (t->left)q.push(t->left);
      if (t->right)q.push(t->right);
    }
    level++;
  }
  return true;
}
};