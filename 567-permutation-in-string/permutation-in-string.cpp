class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int>c1(26), c2(26);
       for(auto &c:s1){
        c1[c-'a']++;
       } 
       int l1 = s1.size();
        for(int i = 0;i<s2.size();i++){
            c2[s2[i]-'a']++;
            if(i - l1 >= 0) c2[s2[i-l1]-'a']--;
            if(c1 == c2) return true; 
        }
        return false;
    }
};