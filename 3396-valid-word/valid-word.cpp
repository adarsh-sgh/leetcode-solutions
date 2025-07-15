class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
       bool co = false, vo = false;
       string vss = "aeiouAEIOU";
       set<char>vs(vss.begin(), vss.end());
       for(auto &c: word){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
            if(vs.count(c)){
                vo = true;
            }else{
                co = true;
            }
        }else if(c >= '0' && c <= '9'){
            continue;
        }else{
            return false;
        }
       } 
       return co && vo;
    }
};