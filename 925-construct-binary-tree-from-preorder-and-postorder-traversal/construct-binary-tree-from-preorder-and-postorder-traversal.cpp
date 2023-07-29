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
    vector<int>pre,post;
    map<int,int>postm;
    TreeNode *cfpp(int i1,int j1,int i2,int j2){
        if(i1 > j1) return nullptr;
        assert(j1-i1==j2-i2);
        assert(pre[i1]==post[j2]);
        TreeNode *r = new TreeNode(pre[i1]);
        i1++;
        j2--;
        if(i1>j1)return r;
        int r2 = postm[pre[i1]];
        int r1 = i1 + r2 - i2;
        r->left = cfpp(i1,r1,i2,r2);
        r->right = cfpp(r1+1,j1,r2+1,j2);
        return r;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        pre = preorder;
        post = postorder;
        for(int i = 0;i<post.size();i++){
            postm[post[i]] = i;
        }
        return cfpp(0,preorder.size()-1,0,postorder.size()-1);
    }
};