class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string w;
        int i = 1;
        for(auto &c:sentence){
            if(c == ' '){
                i++;
                w = "";
                continue;
            }
            w += c;
            if(w == searchWord) return i;
        }    
        return -1;
    }
};