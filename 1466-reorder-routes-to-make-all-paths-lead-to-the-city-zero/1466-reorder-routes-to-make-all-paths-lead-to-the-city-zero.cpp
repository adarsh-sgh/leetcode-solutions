class Solution {
public:
    vector<vector<int>>adj;
    set<vector<int>>final;
    vector<int>vis;
    void dfs(int i){
        if(vis[i]) return;
        vis[i] = true;
        for(auto &&x:adj[i]){
            if(vis[x]) continue;
            final.insert({x,i});
            dfs(x);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        vis.resize(n);
        // final.resize(n);
        for(auto &&x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0);
        int ans = 0;
        for(auto &&x:connections){
            if(!final.count(x))ans++;
        }
        return ans;
    }
};