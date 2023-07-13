class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    bool loop(int n){
        if(vis[n] == 2) return false;
        if(vis[n] == 1) return true;
        vis[n] = 1;
        for(auto &&x:adj[n]){
            if(loop(x)) return true;
        }
        vis[n] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        adj.resize(n);
        vis.resize(n);
        for(auto &&i:p){
            adj[i[1]].push_back(i[0]);
            }
            for(int i =0;i<n;i++){
                if(loop(i)) return false;
            }
            //  loop(0);
            return true;
    }
};