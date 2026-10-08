class Solution {
public:
    string removeOuterParentheses(string s) {
        int oms = 0;
        string ans;
        int i = 1;
       for(int j = 0; j < s.size();j++) {
        char c = s[j];
        if(c == '(')oms++;
        else oms--;
        if(oms == 0){
            ans += s.substr(i, j - i);
            i = j + 2;
        }
       }
       return ans;
    }
};