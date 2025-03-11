class Solution {
public:
    int numberOfSubstrings(string s) {
        // last occurance
       vector<int>loc(3,-1); 
       int ans = 0;
       for(int i = 0;i< s.size();i++){
        loc[s[i] - 'a'] = i;
        int gg = s.size();
        for(auto &x:loc){
            gg = min(gg,x);
        }
        if(gg == -1)continue;
        ans += 1 + gg;
       }
       return ans;
    }
};