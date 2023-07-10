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
    bool empty = true;
    int minDepth(TreeNode* root) {
        if(root==nullptr) return empty?0:1e6;
        empty = false;
        if(!root->left && !root->right) return 1;
        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};