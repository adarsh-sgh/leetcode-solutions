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
    vector<vector<int>>v;
    // depth, pointer
    // map<int,int>dp;
    // depth, num
    vector<array<int,2>>t;
    void dfs(TreeNode*& root, int d, int &idx){
        // int i = dp[d]++;
        // if(v.size() <= d || v[d].size() <= i){
        
        if(t.size() <= idx || t[idx][0] != d){
            root = nullptr;
            return;
        }else{
            // root->val = v[d][i];
            root->val = t[idx][1];
            idx++;
            root -> left = new TreeNode();
            root -> right = new TreeNode();
            dfs(root->left, d+1, idx);
            dfs(root->right, d+1, idx);
        }
    }
    TreeNode* recoverFromPreorder(string traversal) {
       // fill the v as v[depth] = values
       // run a bfs to recover tree from v 
       int dc = 0, num = 0;
       for(int i = 0;i < traversal.size();i++){
        auto &c = traversal[i];
        if(c == '-')dc++;
        else {
            num = num * 10 + (c - '0');
            if(i == traversal.size()-1 || traversal[i+1] == '-'){
                // if(v.size() == dc)v.push_back({});
                // v[dc].push_back(num);
                t.push_back({dc, num});
                num = 0;
                dc = 0;
            }
        }
       }
       for(auto &x:v){
        for(auto &y:x){
            cerr<<y<<' ';
        }
        cout<<endl;
       }
       TreeNode * ans = new TreeNode();
       int dd = 0;
       dfs(ans, 0, dd);
       return ans;
    }
};