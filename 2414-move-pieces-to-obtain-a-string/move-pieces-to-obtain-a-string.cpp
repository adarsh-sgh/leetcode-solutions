class Solution {
public:
    bool canChange(string s, string t) {
        string sn, tn;
        for(auto &c:s){
            if(c == '_')continue;
            sn += c;
        }
        for(auto &c:t){
            if(c == '_')continue;
            tn += c;
        }
        if(sn != tn) return false;
        int cls = 0, clt = 0;
        int crs = 0, crt = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == 'L' )cls++;
            if(s[i] == 'R') crs++;
            if(t[i] == 'L')clt++;
            if(t[i] == 'R')crt++;
            if(clt < cls)return false;
            if(crt > crs) return false;
        }
        return true;
    }
};