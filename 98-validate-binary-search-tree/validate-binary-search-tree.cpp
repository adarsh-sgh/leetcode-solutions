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
     bool ivb(TreeNode * root, long long mx,long long mn){
        if(!root) return true;
        if(root-> val >= mx || root -> val <= mn)return false;
        return ivb(root-> left, min(mx, 1ll * root->val), mn) && ivb(root-> right, mx, max(mn, 1ll * root->val));
     }
     
    bool isValidBST(TreeNode* root) {
        return ivb(root, INT_MAX + 1ll, INT_MIN - 1ll);
    }
};