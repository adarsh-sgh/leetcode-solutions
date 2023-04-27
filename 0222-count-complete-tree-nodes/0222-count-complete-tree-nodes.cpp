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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int ld = -1,rd = -1;
        TreeNode *t = root->left;
        while(t){
            ld++;
            t = t->left;
        }
        t =root->right;
        while(t){
            rd++;
            t = t->left;
        }
        cout<<root->val<<' '<<ld<<' '<<rd<<endl;
        if(ld == rd){
            return (1<<(ld+1)) + countNodes(root->right);
        }else{
            return (1<<(rd+1))  + countNodes(root->left);
        }
        return 0;
    }
};