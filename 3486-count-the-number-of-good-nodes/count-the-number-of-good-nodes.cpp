class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>>adj(n);
        for(auto &e:edges){
            auto x = e[0], y = e[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int ans = 0;
        function<int(int,int)>dfs = [&](int x,int p)->int{
            int pv = -1;
            int sum = 1;
            bool gg = true;
            for(auto &a:adj[x]){
                if(a==p)continue; 
                int curr = dfs(a,x);
                if(pv != -1 && pv != curr) gg = false;
                pv = curr;
                sum += curr;
            }
            ans += gg;
            return sum;
        };
        dfs(0,-1);
        return ans;
    }
};