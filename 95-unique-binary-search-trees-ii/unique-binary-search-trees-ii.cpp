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
    vector<TreeNode *>gt(int start,int end){
        if(start > end) return {nullptr};
        vector<TreeNode *>res;
        for(int root = start;root <= end;root++){
            vector<TreeNode *>left = gt(start,root-1);
            vector<TreeNode *>right = gt(root+1,end);
            for(auto &&l:left){
                for(auto &&r:right){
                    res.push_back(new TreeNode(root,l,r));
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return gt(1,n);
    }
};