/**
 * Definition for a binary tree node.

 */
class Solution {
public:
   #define dbg(...) 42;
    vector<int> pre, pos;
    map<int, int> postMp;

    // Make a tree considering i1, j1 of preorder and i2, j2 of postorder
   TreeNode* dfs(int i1, int j1, int i2, int j2) {
    if (i1 > j1 || i1 >= pre.size()|| i1 < 0) return nullptr;
    // Use .at() for bounds-checked access
  dbg(i1, j1, i2, j2);
  assert(j1 - i1 == j2 - i2);
    TreeNode* root = new TreeNode(pre.at(i1));
    if(i1 == j1) return root;
    // Now decide how to split the ranges between left and right subtrees
    // i1 + 1 will be the root of the left subtree
    // This should be the last index of postorder sent to the left
    // Also, the size of segments sent to left and right will be the same
    // i.e., j1 - i1 == j2 - i2 always
    int i1l = i1 + 1;
    int j2l = postMp.at(pre.at(i1l)); // Use .at() for bounds-checked access

    // Make j1 - i1 == j2 - i2
    // i1 and j2 are consumed here
    int j1l = i1l + j2l - i2;

    // Recursively build the left and right subtrees
    root->left = dfs(i1l, j1l, i2, j2l);
    root->right = dfs(j1l + 1, j1, j2l + 1, j2 - 1);

    return root;
}

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        pre = preorder;
        pos = postorder;

        // Populate the postorder map using .at() for bounds-checked access
        for (int i = 0; i < postorder.size(); i++) {
            postMp[postorder.at(i)] = i;
        }

        // Start the DFS with the full ranges of preorder and postorder
        return dfs(0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};