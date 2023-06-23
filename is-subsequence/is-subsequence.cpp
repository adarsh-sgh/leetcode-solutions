class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(true){
            if(i>=s.size())return true;
            if(j>=t.size())return false;
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return true;
    }
};