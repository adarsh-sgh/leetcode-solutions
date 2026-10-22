/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string s = "";
      ser(root, s);
      return s;
    }
    void ser(TreeNode *root, string &s){
        if(root){
            s += to_string(root->val);
            s += " ";
            ser(root -> left, s);
            ser(root->right, s);
        }else{
            s += "# ";
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       std::istringstream  iss(data);
        return des(iss);
    }
    TreeNode *des(istringstream &iss){
         string val;
         iss>>val;
         if(val != "#"){
            TreeNode *root = new TreeNode(stoi(val));
            root -> left = des(iss);
            root -> right = des(iss);
            return root;
         }
         return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));