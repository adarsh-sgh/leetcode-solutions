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
   #define dbg(...) 42; 
// indices of depths
map<int, vector<int>>ind;
// s-> node,depth
TreeNode* rfp(vector<pair<int, int>>& s, int i, int j) {
  if (i > j)return nullptr;
  dbg(i, j);
  TreeNode* r = new TreeNode(s[i].first);
  int dchild = s[i].second + 1;
  auto& v = ind[dchild];
  int lchildind = i + 1;
  int rchildind = j + 1;
  auto it = upper_bound(v.begin(), v.end(), lchildind);
  if (it != v.end()) rchildind = *it;

  r->left = rfp(s, lchildind, min(rchildind - 1, j));
  r->right = rfp(s, rchildind, j);
  return r;
}

TreeNode* recoverFromPreorder(string traversal) {
  vector<pair<int, int>>s;
  int d = 0, curr = 0;
  for (int i = 0;i < traversal.size();i++) {
    char c = traversal[i];
    if (c == '-') {
      if (curr) {
        s.push_back({ curr,d });
        curr = 0;
        d = 0;
      }
      d++;
    }
    else {
      curr = curr * 10 + c - '0';
    }
  }
  if (curr) {
    s.push_back({ curr,d });
  }
  dbg(s);
  for (int i = 0;i < s.size();i++) {
    ind[s[i].second].push_back(i);
  }
  dbg(ind);
  return rfp(s, 0, s.size() - 1);
}

};