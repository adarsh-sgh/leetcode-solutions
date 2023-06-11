class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>m1,m2;
        for(auto &&c:s)m1[c]++;
        for(auto &&c:t)m2[c]++;
        int ans = 0;
        for(auto &&[x,y]:m1){
            ans += max(0,y-m2[x]);
        }
        return ans;
    }
};