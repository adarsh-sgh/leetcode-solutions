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
    vector<vector<int>>v;
    void dfs(TreeNode* root, int lev){
        if(root == nullptr)return;
        if(v.size() <= lev){
            v.push_back({});
        }
        assert(v.size() > lev);
        v[lev].push_back(root->val);
        dfs(root->left, lev+1);
        dfs(root->right, lev + 1);
    }
  vector<int>ptr;
   void dfs2(TreeNode* root, int lev){
        if(root == nullptr)return;
        root -> val = v[lev][ptr[lev]++];
        // root -> val = 4;
        dfs2(root->left, lev + 1);
        dfs2(root->right, lev + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root, 0);
        for(int i = 1;i<v.size();i+=2){
            reverse(v[i].begin(),v[i].end());
        }     
        ptr.resize(v.size());
        dfs2(root,0 );
        return root;
    }
};