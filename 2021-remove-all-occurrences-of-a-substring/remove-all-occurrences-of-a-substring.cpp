class Solution {
public:
    string removeOccurrences(string s, string part) {
       string sn;
       for(auto &c:s){
        sn += c;
        if(sn.size() >= part.size() && sn.substr(sn.size() - part.size()) == part) sn = sn.substr(0, sn.size() - part.size());
       } 
       return sn;
    }
};