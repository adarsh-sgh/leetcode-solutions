class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
       // do a dfs 
       // if sumLeft % k == 0 sumleft = 0, ans ++;  (cut the left edge)
       vector<vector<int>>adj(n);
       for(auto &e:edges){
        // auto [x,y] = e;
        auto x = e[0], y = e[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
       }
       int ans = 0;
       int sum = 0;
       function<int(int, int)> dfs = [&](int x,int p)->int{
        int sum = values[x];
        for(auto &a:adj[x]){
           if(a == p) continue;
           sum += dfs(a,x); 
        }
        sum  %= k;
        if(sum == 0) ans++;
        return sum;
       };
       dfs(0,-1);
       return ans;
    }
};