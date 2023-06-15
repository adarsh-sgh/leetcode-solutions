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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ansLevel = -1;
        int maxSum = INT_MIN;
        int lvl = 1;
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                auto x = q.front();
                q.pop();
                sum += x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
             if(sum > maxSum){
                maxSum = sum;
                ansLevel = lvl;
            }
            lvl++;
        }
        return ansLevel;
    }
};