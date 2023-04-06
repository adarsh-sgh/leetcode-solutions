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
    int sum = 0;
    void sn(TreeNode *r, int sm){
        if(!r) {
            // sum += sm;
            return;
        }
       
        sm *=10;
        sm += r->val;
         if(!r->left && !r->right){
            sum += sm;
        }
        sn(r->left,sm);
        sn(r->right,sm);
    }
    int sumNumbers(TreeNode* root) {
        sn(root,0);
        return sum;
        // return root->val + 10 * (sumNumbers(root->left) + sumNumbers(root->right));
    }
};