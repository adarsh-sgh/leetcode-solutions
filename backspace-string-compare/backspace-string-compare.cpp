class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a,b;
        for(auto &&c:s){
            if(c=='#' && a.size())a.pop_back();
            else if(c!='#') a.push_back(c);
        }

         for(auto &&c:t){
            if(c=='#' && b.size())b.pop_back();
            else if(c!='#')b.push_back(c);
        }
        return a == b;
    }
};