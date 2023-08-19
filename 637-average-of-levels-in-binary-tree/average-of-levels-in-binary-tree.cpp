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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        vector<double>ans;
        while(q.size()){
            int qn = q.size();
            long long sm = 0, cnt = 0;
            while(qn--){
                auto t = q.front();
                q.pop();
                sm += t->val;
                cnt++;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(1.0 * sm/cnt);
        }
        return ans;
    }
};