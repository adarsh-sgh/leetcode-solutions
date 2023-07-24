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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n<=0) return {};
        
        if(n==1) return {new TreeNode()};
        vector<TreeNode*>ans;
        for(int left = 1;left <n;left +=2){
            auto lv = allPossibleFBT(left);
            auto rv = allPossibleFBT(n-1-left);
            for(auto &&x:lv){
                for(auto &&y:rv){
                    TreeNode *r = new TreeNode();
                    r->left = x;
                    r->right = y;
                    ans.push_back(r);
                }
            }
        }
        return ans;
    }
};