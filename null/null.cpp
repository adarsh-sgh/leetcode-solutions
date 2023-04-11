class Trie {
public:
    struct TrieNode{
        bool eof = false;
        TrieNode* childs[26] ;
    };
    TrieNode *root= new TrieNode();
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(auto &&c:word){
            if(!curr->childs[c-'a']){
                curr->childs[c-'a'] = new TrieNode();
            }
            curr = curr->childs[c-'a'];
        }
        curr->eof = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(auto &&c:word ){
            if(!curr->childs[c-'a']) return false;
            curr = curr->childs[c-'a'];
        }
        return curr->eof;
    }
    
    bool startsWith(string prefix) {
TrieNode *curr = root;
        for(auto &&c:prefix ){
            if(!curr->childs[c-'a']) return false;
            curr = curr->childs[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */