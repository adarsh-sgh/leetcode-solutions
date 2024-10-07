class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        set<int> sus;
        vector<vector<int>> adj(n);
        for (auto& i : invocations) {
            adj[i[0]].push_back(i[1]);
        }
        vector<int> vis(n);
        function<void(int)> dfs = [&](int x) {
            if(vis[x])return;
            sus.insert(x);
            vis[x] = 1;
            for (auto& a : adj[x]) {
                dfs(a);
            }
        };
        dfs(k);
        // for(auto &x:sus)cout<<x<<' ';
        // cout<<"---";
         for (auto& i : invocations) {
            if (sus.count(i[1]) && !sus.count(i[0])) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(),0);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!sus.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};