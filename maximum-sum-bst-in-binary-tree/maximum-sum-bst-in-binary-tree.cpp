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
 #define dbg(...) 42;
class Solution {
public:
    int ans = 0;
// sum min max
vector<int>dfs(TreeNode*& r) {
  vector<int>lf{0, INT_MAX, INT_MIN}, rt{ 0,INT_MAX,INT_MIN };
  if (r->left) {
    lf = dfs(r->left);
  }
  if (r->right) {
    rt = dfs(r->right);
  }
  dbg(lf, rt, r->val);
  if ((!r->left || lf[2] < r->val) && (!r->right || rt[1] > r->val)) {
    ans = max(ans,r->val + lf[0] + rt[0]);
    return { r->val + lf[0] + rt[0],min({lf[1],rt[1],r->val}),max({r->val,lf[2],rt[2]}) };
  }
  return { 0,INT_MIN,INT_MAX };
}
int maxSumBST(TreeNode* root) {
  dfs(root);
  return ans;
}
};