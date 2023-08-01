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
    string ans;
    void dfs(TreeNode *r, string &s){
        if(!r) return;
        s += char(r->val + 'a');
        if(!r->left && !r->right){
            string temp = s;
            reverse(temp.begin(),temp.end());
            if(ans.empty() || ans > temp) ans = temp;
        }
        dfs(r->left,s);
        dfs(r->right,s);
        s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string s;
        dfs(root,s);
        return ans;
    }
};