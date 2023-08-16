class Solution {
public:
    vector<vector<int>>adj;
    bool sim(string &a, string &b){
        int d = 0;
        for(int i = 0;i<a.size();i++){
            d += a[i] != b[i];
        }
        return d <= 2;
    }
    vector<int>vis;
    void dfs(int x){
        if(vis[x])return;
        vis[x] = true;
        for(auto &&a:adj[x]){
            dfs(a);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vis.resize(n);
        adj.resize(n,vector<int>(n));
        for(int i = 0;i<strs.size();i++){
            for(int j = i+1;j<strs.size();j++){
                if(sim(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += !vis[i];
            dfs(i);
        }
        return ans;
    }
};