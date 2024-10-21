class Solution {
public:
    int ans = 0;
    void ms(string &s,int i, map<string,int>&mp){
       if(i == s.size()) ans = max(ans, (int)mp.size());
       string curr; 
       for(int j = i;j<s.size();j++){
        curr += s[j];
        if(!mp.count(curr)){
            mp[curr]++;
            ms(s,j+1,mp);
            mp.erase(curr);
        }
       } 
    }
    int maxUniqueSplit(string s) {
       map<string,int>mp;
       ms(s,0,mp);
       return ans; 
    }
};