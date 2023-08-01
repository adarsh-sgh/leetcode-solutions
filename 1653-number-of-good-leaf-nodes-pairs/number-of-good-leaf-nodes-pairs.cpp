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
    set<TreeNode *>leaf;
    map<TreeNode *,TreeNode *>par;
    void dfs(TreeNode *r){
        if(!r) return;
        if(!r->left && !r->right)leaf.insert(r);
        if(r->left){
            par[r->left] =r;
            dfs(r->left);
            }
        if(r->right){
            par[r->right] = r;
            dfs(r->right);
            }
    }

    int cp(TreeNode *r, int d, TreeNode *p){

        if(d < 0 || !r){
            return 0;
        }
        if(leaf.count(r) && p) return 1;
        int res = 0;
        if(r->right != p)res += cp(r->right,d-1,r);
        if(r->left != p) res += cp(r->left,d-1,r);
        if(par[r] != p) res += cp(par[r],d-1,r);
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root);
        int ans = 0;
        for(auto &&r:leaf){
            ans += cp(r,distance,nullptr);
        }
        return ans/2;
    }
};