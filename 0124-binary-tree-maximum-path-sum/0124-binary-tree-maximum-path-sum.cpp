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
    map<TreeNode*,int>mp;
    int msps(TreeNode*root){
        if(!root) return 0;
        if(mp.count(root)) return mp[root];
        mp[root] = root->val+max(max(msps(root->left),msps(root->right)),0);
        return mp[root];
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return INT_MIN ;
        int x = max(msps(root->left),0)+max(msps(root->right),0)+root->val;
        int y = maxPathSum(root->left);
        int z = maxPathSum(root->right);
        return max(x,max(y,z));
    }
};