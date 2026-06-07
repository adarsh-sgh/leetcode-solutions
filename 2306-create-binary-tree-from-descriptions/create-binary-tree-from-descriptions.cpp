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
    map<int,TreeNode*>m;
    set<TreeNode *>childs;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        for(auto &&x:descriptions){
            auto p = x[0], c = x[1], il = x[2];
            TreeNode *par = m[p];
            if(!par) m[p] = par = new TreeNode(p);
            TreeNode *ch = m[c];
            if(!ch) m[c] = ch = new TreeNode(c);
            if(il){
                par->left = ch;
            }else{
                par->right = ch;
            }
            childs.insert(ch);
        }
        for(auto &&[x,y]:m){
            if(!childs.count(y))return y;
        }
        return nullptr;
    }
};