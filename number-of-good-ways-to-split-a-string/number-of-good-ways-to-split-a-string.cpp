class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int>pref(n+1),suff(n+1);
        set<char>se;
        for(int i = 0;i<n;i++){
            pref[i] = se.size();
            se.insert(s[i]);
        }
        se.clear();
        for(int j = n-1;j>=0;j--){
            se.insert(s[j]);
            suff[j] = se.size();
        }
        int cnt = 0;
        for(int i = 0;i<n;i++ ){
            if(pref[i]==suff[i])cnt++;
        }
        return cnt;
    }
};