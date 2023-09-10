class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>indegree(n);
        vector<vector<int>>adj(n);
        for(auto &p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int>q;
        for(int i = 0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>topo;
        while(q.size()){
            auto t = q.front();
            q.pop();
            topo.push_back(t);
            for(auto &a:adj[t]){
                indegree[a]--;
                if(indegree[a]==0)q.push(a);
            }
        }
        if(topo.size()< n) return {};
        return topo;

    }
};