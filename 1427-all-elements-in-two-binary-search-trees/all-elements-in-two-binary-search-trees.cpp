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
    vector<int>v1,v2;
    void io(TreeNode *r){
        if(!r) return;
        io(r->left);
        v1.push_back(r->val);
        io(r->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        io(root1);
        swap(v1,v2);
        io(root2);
        int i = 0, j = 0;
        vector<int>ans(v1.size() + v2.size());
        for(int x = 0;x < ans.size();x++){
            if(i >= v1.size())ans[x] = v2[j++];
            else if(j >= v2.size()||v1[i] <= v2[j])ans[x] = v1[i++];
            else ans[x] = v2[j++];
        }
        return ans;
    }
};