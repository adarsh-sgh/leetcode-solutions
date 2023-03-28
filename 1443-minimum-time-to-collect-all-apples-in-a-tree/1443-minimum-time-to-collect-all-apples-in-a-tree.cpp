class Solution {
public:
    vector<int>vis;
    vector<vector<int>>adj;
    vector<bool>ha;
    int ans = 0;
    bool dfs(int n){
        vis[n] = true;
        // child has apple
        bool hac = false;
        for(auto &&x:adj[n]){
            if(vis[x]) continue;
            bool curr = dfs(x);
            ans += 2 * curr;
            hac = curr || hac;
        }         
         return ha[n] || hac;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vis.resize(n);
        adj.resize(n);
        ha = hasApple;

        for(auto &&x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0);
        return ans;
        
    }
};