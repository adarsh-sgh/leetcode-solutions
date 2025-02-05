class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       vector<int>v1(26);
       vector<int>v2(26);
       for(auto &c:s1)v1[c-'a']++;
       for(auto &c:s2) v2[c-'a']++;
       if(v1 != v2) return false;
       int diff = 0;
       for(int i = 0;i < s1.size();i++){
        if(s1[i] != s2[i])diff++;
       }
       return diff <= 2;
    }
};