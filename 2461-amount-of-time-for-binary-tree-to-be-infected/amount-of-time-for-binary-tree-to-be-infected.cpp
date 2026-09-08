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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    vector<vector<int>>adj;
    void dfs(TreeNode *r){
        if(!r) return;
        if(r -> left){
            adj[r->val].push_back(r->left->val);
            adj[r->left->val].push_back(r->val);
            dfs(r->left);
        }
        if(r->right){
            adj[r->val].push_back(r->right->val);
            adj[r->right->val].push_back(r->val);
            dfs(r->right);
        }
    }
    vector<int>vis;
    int ans = 0;
    void dfs2(int x, int dis){
        if(vis[x]) return;
        vis[x] = true;
        ans = max(ans, dis);
        for(auto &a:adj[x]){
            dfs2(a,dis+1);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        adj.resize(1e5+1);
        vis.resize(1e5+1); 
        
        dfs(root);
        dfs2(start, 0);
        return ans;
        
    }
};