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
    int cost(vector<int>&v){
           auto vc = v;
           sort(vc.begin(),vc.end());
           map<int,int>mp;
           for(int i = 0;i<v.size();i++){
            mp[vc[i]] = i;
           } 
           int cst = 0;
           for(int i = 0;i< v.size();i++){
            while(v[i] != vc[i]){
                swap(v[i], v[mp[v[i]]]);
                cst++;
            }
           }
           return cst;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int cst = 0;
        while(q.size()){
           int qn = q.size();
           vector<int>v;
           while(qn--){
            auto t = q.front();
            q.pop();
            v.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
           } 
           cst += cost(v);
        }
        return cst;
    }
};