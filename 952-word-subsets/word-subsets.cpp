class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
       vector<int>v2(26);
       for(auto &w:words2){
        vector<int>vl(26);
        for(auto &c:w)vl[c - 'a']++;
        for(int i = 0;i<26;i++)v2[i] = max(v2[i], vl[i]);
       } 
       vector<string>ans;
       for(auto &w:words1){
        vector<int>vl(26);
        for(auto &c:w)vl[c - 'a']++;
        for(int i = 0;i<26;i++){
            if(vl[i] < v2[i])break;
            if(i == 25) ans.push_back(w);
        }
       }
       return ans;
    }
};