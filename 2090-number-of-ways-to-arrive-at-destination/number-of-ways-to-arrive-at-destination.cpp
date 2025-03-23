class Solution {
public:
    const long long mod = 1e9 + 7;
    long long countPaths(long long n, vector<vector<int>>& roads) {
        vector<vector<array<long long,2>>>adj(n);

        for(auto &e:roads){
           adj[e[0]].push_back({e[1],e[2]});
           adj[e[1]].push_back({e[0],e[2]});
        }

        // shortest time => weighted bfs / dijkstra 
        long long inf = 1e12;
        vector<long long>dis(n,inf);
        vector<long long>cnt(n,0);
        dis[0] = 0;
        cnt[0] = 1;
        priority_queue<vector<long long>,vector<vector<long long>>, greater<vector<long long>>>pq;
        pq.push({0,0});

        while(pq.size()){
            auto t = pq.top();
            long long w = t[0], x = t[1];
            pq.pop();
            if(w > dis[x])continue;
            for(auto &[a,w]:adj[x]){
                if(dis[a] < dis[x] + w)continue;
                if(dis[a]== dis[x] + w){
                    cnt[a]+= cnt[x];
                    cnt[a] %= mod;
                    continue;
                }
                dis[a] = dis[x] + w;
                cnt[a] = cnt[x];
                pq.push({dis[a], a});
            }
        }
        for(auto &x:cnt)cout<<x<<' ';
        return cnt.back()%mod;
    }
};