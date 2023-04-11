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
    int ans = -1;
    int k;
    void io(TreeNode *root){
        if(!root) return;
        
        io(root->left);
        if(--k==0) {
        ans = root->val;
        return;
        }
        io(root->right);
    }
    int kthSmallest(TreeNode* root, int K) {
        k = K;
        io(root);
        return ans;
    }
};