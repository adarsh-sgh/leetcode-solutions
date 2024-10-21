class Solution {
public:
    set<string>se;
    int ans = 0;
    string s;
    void dfs(int i){
        if(i == s.size()){
            ans = max(ans, (int)se.size());
        }
        string curr;
        for(int j = i;j<s.size();j++){
            curr += s[j];
            if(se.count(curr))continue;
            se.insert(curr);
            dfs(j+1);
            se.erase(curr);
        }
    }
    int maxUniqueSplit(string S) {
       s = S;
        dfs(0);
        return ans;
    }
};