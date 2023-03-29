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
    // reverse in order
    //right root left
    int sum = 0;
    void rio(TreeNode *r){
        if(!r) return;
       
        rio(r->right);
         sum += r->val;
        r->val = sum;

        rio(r->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        rio(root);
        return root;
    }
};