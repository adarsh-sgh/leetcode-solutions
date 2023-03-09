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
    // bool has1(TreeNode &*r){
    //     if(!r) return false;
    //     if(r->val == 1) return true;
    //     return has1(r->left) || has1(r->right);
    // }
    void dfs(TreeNode *&r){
        if(!r) return;
        dfs(r->left);
        dfs(r->right);
        if(r->val == 0 && (!r->left) && (!r->right)){
            cout<<"lol";
            r = nullptr;
        }
        if(!r) return;
        // if(!has1(r->left)) r->left = nullptr;
        // if(!has1(r->right)) r->right = nullptr;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};