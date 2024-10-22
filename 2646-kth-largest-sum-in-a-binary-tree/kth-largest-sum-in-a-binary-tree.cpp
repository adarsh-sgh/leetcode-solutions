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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<long long>lsum;
        q.push(root);
        while(q.size()){
            int qn = q.size();
            long long sum = 0;
            while(qn--){
                auto t = q.front();
                q.pop();
                sum += t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            lsum.push_back(sum);
        }
        sort(lsum.rbegin(),lsum.rend());
        for(auto &x:lsum) cout<<x<<' ';
        if(k > lsum.size()) return -1;
        return lsum[k-1];
    }
};