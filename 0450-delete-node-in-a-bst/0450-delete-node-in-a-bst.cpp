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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val == key){
            if(!root->left && !root->right) return nullptr;
            if(!root->left||!root->right){
                return root->left ? root->left:root->right;
            }
            // find largest element smaller than key
            TreeNode *curr = root->left,*prev = nullptr;
            if(!curr){
                return root->right;
            }
            while(curr->right){
                prev = curr;
                curr = curr->right;
            }
            root->val = curr->val;
            root->left = deleteNode(root->left,curr->val);
            return root;
        }
        root->left = deleteNode(root->left,key);
        root->right = deleteNode(root->right,key);
        return root;
    }
};