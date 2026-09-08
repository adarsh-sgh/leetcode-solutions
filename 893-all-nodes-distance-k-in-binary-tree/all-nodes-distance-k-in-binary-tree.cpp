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
    vector<int>ans;
    int K;
    void dfs2(int x, int dis){
        if(vis[x]) return;
        vis[x] = true;
        if(dis == K){
            ans.push_back(x);
        }
        for(auto &a:adj[x]){
            dfs2(a,dis+1);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        K = k;
       adj.resize(501,vector<int>());
       dfs(root);
        vis.resize(501,0);
       dfs2(target->val, 0);
       return ans;
    }
};