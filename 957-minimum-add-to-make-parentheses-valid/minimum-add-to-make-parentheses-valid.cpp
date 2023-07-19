class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0,o = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(')o++;
            else o--;
            if(o<0){
                o = 0;
                ans++;
            }
        }
        return ans + o;
    }
};