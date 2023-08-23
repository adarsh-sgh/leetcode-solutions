class Solution {
public:
    int inf = 1e9 + 5;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<array<int,2>>>adj;
        adj.resize(n);
        for(auto &&t:times){
            t[0]--;
            t[1]--;
            adj[t[0]].push_back({t[1],t[2]});
        }
        k--;

        vector<int>dis(n,inf);
        dis[k] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,k});
        vector<int>vis(n);
        while(pq.size()){
            auto t = pq.top();
            int u = t[1], w = t[0];
            pq.pop();
            if(vis[u])continue;
            vis[u] = true;
            for(auto &&a:adj[u]){
                if(dis[a[0]] <= dis[u] + a[1])continue;
                dis[a[0]] = dis[u] + a[1];
                pq.push({dis[a[0]],a[0]});
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++) ans = max(ans,dis[i]);
        if(ans > 1e9) return -1;
        return ans;
    }
};