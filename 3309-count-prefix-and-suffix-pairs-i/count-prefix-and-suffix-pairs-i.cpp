class Solution {
public:
    bool isPaS(string &s1,string&s2){
        return s2.substr(0,s1.size()) == s1 && s1 == s2.substr(s2.size() - s1.size(), s1.size());
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
       for(int i = 0;i<words.size();i++){
        for(int j = i+1;j<words.size();j++){
            ans += isPaS(words[i], words[j]);
        }
       } 
       return ans;
    }
};