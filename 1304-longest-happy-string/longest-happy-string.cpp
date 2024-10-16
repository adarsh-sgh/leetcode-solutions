class Solution {
public:
    void dfs(string &s, vector<array<int,2>>&v){
        sort(v.begin(),v.end());
        if(v.back()[0] == 0) return;
        if(s.size() < 2 || (char)v.back()[1] != s.back() || (char)v.back()[1] != s[s.size() - 2]){
            s += v.back()[1];
            v.back()[0]--;
        }else if(v[1][0] == 0) return;
        else {
            s += v[1][1];
            v[1][0]--;
        }
        dfs(s,v);
    }
    string longestDiverseString(int a, int b, int c) {
        string ans;
        vector<array<int,2>> v = {{a,'a'},{b,'b'},{c,'c'}};
       dfs(ans,v) ;
       return ans;
    }
};