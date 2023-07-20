class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26);
        for(auto &&c:s)v[c-'a']++;
        vector<int>vt;
        for(auto &&x:v){
        if(x)vt.push_back(x);
        }
        v = vt;
        sort(v.begin(),v.end());
        set<int>se;
        int ans = 0;
        for(int i = 0;i<v.size();i++){
            while(v[i] && !se.insert(v[i]).second){v[i]--;ans++;}
        }
        return ans;
    }
};