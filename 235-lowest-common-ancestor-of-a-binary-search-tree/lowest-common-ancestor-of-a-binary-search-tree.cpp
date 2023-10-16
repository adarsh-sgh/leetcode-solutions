/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int sm = min(p->val,q->val), lg = max(p->val,q->val);
        while(root){
            if(lg < root->val){
                root = root->left;
            }else if(sm > root->val){
                root = root->right;
            }else{
                return root;
            }
        }
        return nullptr;
    }
};