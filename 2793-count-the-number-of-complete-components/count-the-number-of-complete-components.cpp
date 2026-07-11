class Solution {
public:
    vector<vector<int>>adj;
    vector<int>vis;
    map<int,int>nodecnt;
    // return size of group
    int dfs(int x){
        assert(vis[x] == 0);
        vis[x] = true;
        int cnt = 1;
        for(auto &a:adj[x]){
            if(vis[a]) continue;
            int d = dfs(a);
            if(d == -1 || nodecnt[x] != nodecnt[a]) cnt = -1;
            if(cnt != -1)cnt += d;
        }
        return cnt;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // count size using dfs
        // each node appears size - 1 => ans++;
        adj.resize(n);
        vis.resize(n,0);
        
        for(auto &e:edges){
           int x = e[0], y = e[1];
           nodecnt[x]++;
           nodecnt[y]++;
           adj[x].push_back(y);
           adj[y].push_back(x);
        }
        int cnt = 0;
        // size of current group being dfsed
        int szc = -1;
        
        int ans = 0; 
        for(int i = 0;i < n;i++){
            if(vis[i])continue;
            // find size of group
            int sz = dfs(i);
            cout<<i<<"<-i  sz->"<<sz<<'\n';
            if(sz - 1 == nodecnt[i]){
                ans++;
            }
        }
        return ans;
    }
};