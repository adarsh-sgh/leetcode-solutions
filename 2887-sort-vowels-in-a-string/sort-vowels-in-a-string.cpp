class Solution {
public:
    string sortVowels(string s) {
        set<char>vo = {'A','E','I','O','U','a','e','i','o','u'};
        string vs;
        for(auto &c:s){
            if(vo.count(c)){
                vs.push_back(c);
            }
        }
        sort(vs.rbegin(), vs.rend());
        for(auto &c:s){
            if(!vo.count(c))continue;
            char cn = vs.back();
            vs.pop_back();
            c = cn;
        }
        return s;
    }
};