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
    int ans = 0;
    // return sum, cnt
    array<int,2> avg(TreeNode *root){
        if(!root) return {0,0};
        auto [s1,c1] = avg(root->left);
        auto [s2,c2] = avg(root->right);
        if(root -> val == (s1 + s2 + root->val)/(c1 + c2 + 1)){
            ans++;
        }
        return {s1 + s2 + root->val, c1 + c2 + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        avg(root);
        return ans; 
    }
};