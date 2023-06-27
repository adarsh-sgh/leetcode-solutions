struct TrieNode {
  TrieNode* child[26];
  bool eow;
};
class StreamChecker {
public:
  TrieNode* root = new TrieNode();
  StreamChecker(vector<string>& words) {
    for (auto&& w : words) {
      TrieNode* curr = root;
      for (auto&& c : w) {
        if (!curr->child[c - 'a']) {
          curr->child[c - 'a'] = new TrieNode();
        }
        curr = curr->child[c - 'a'];
      }
      curr->eow = true;
    }
  }
  vector<TrieNode*>v{ root };
  bool query(char letter) {
    vector<TrieNode*>temp;
    bool ans = false;
   for(auto &&it:v){
    if(!it||!it->child[letter - 'a'])continue;
    temp.push_back(it->child[letter - 'a']);
    if(it->child[letter - 'a']->eow) ans =  true;
   }
   v = temp;
   v.push_back(root);
   return ans;
  }


};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */