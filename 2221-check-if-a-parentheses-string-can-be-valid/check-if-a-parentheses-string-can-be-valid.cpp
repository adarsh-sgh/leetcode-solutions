class Solution {
public:
    bool canBeValid(string s, string locked) {
        int o = 0, c = 0, ul = 0;
        for(int i = 0;i< s.size();i++){
            if(locked[i] == '0')ul++;
            else if(s[i] == '(')o++;
            else c++;
        }
        // how many locked can be changed to open 
        int ulo = c - o;
        ul -= ulo;
        if(ul % 2) return false;
        ulo += ul/2;
        if(ulo < 0) return false;

        c = 0, o = 0;
       for(int i = 0;i< s.size();i++){
        if(locked[i] == '0'){
            if(ulo-- > 0)o++;
            else c++;
        }else if(s[i] == '('){
            o++;
        }else{
            c++;
        }
        if(c > o) return false;
       }
       return c == o;
    }
};