class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        for(auto &c:str1){
            if(i == str2.size())break;
            if(c == str2[i] || (c - 'a' + 1) % 26 == str2[i] - 'a'){
                i++;
            }
        }
        return i == str2.size();
    }
};