class Solution {
public:
    int maxScore(string s) {
       int o = 0, z = 0;
       for(auto &x:s)
        x == '1'? o++ : z++;
       int oc = 0, zc = 0; 
       int scr = 0;
       for(int i = 0;i<s.size() - 1;i++){
        if(s[i] == '0')zc++;
        else oc++;
        scr = max(scr, zc + o - oc);
       } 
       return scr;
    }
};