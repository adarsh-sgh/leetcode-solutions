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
    map<string,int>se;
    vector<TreeNode *>ans;

    string po(TreeNode *r){
        if(!r) return "#";
        string l = po(r->left);
        string rt = po(r->right);
        string res = to_string(r->val) +',' +  l + rt; 
        if(se[res]==1)ans.push_back(r);
        se[res]++;
        return res;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        po(root);
        return ans;
    }

};