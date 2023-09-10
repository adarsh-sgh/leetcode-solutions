class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(auto &r:richer){
            adj[r[0]].push_back(r[1]);
            indeg[r[1]]++;
        }
        queue<int>q;
        for(int i = 0;i<n;i++){
            if(!indeg[i]) q.push(i);
        }
        vector<int>ans(n);
        iota(ans.begin(),ans.end(),0);
        while(q.size()){
            auto t = q.front();
            q.pop();

            for(auto &a:adj[t]){
                if(--indeg[a] == 0){
                    q.push(a);
                }
                if(quiet[ans[t]] < quiet[ans[a]]){
                    ans[a] = ans[t];
                }
            }
        }
        return ans;
    }
};