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
    vector<TreeNode*>ans;
    unordered_set<int>d;
    void dfs(TreeNode* &r){
        if(!r) return;
        if(d.count(r->val)){
            if(r->left && !d.count(r->left->val)) ans.push_back(r->left);
            if(r->right && !d.count(r->right->val)) ans.push_back(r->right);
            dfs(r->left);
            dfs(r->right);
            r = nullptr;
        }else{
             dfs(r->left);
            dfs(r->right);
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto&&x:to_delete){
            d.insert(x);
        }
        if(root && !d.count(root->val))ans.push_back(root);
        dfs(root);
        return ans;
    }
};