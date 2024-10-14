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
    vector<int>sz;
    // returns -1 if root not perfect tree
    // else returns it's size
    int dfs(TreeNode *root){
        if(!root) return 0;
        // if(root->left ^ root -> right){
        //     return -1;
        // }
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l == -1 || l != r) return -1;
        sz.push_back(1 + l+r);
        return l + r + 1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(sz.rbegin(),sz.rend());
        if(k > sz.size()) return -1;
        // for(auto &x:sz) cout<<x<<' ';
        return sz[k-1];
    }
};