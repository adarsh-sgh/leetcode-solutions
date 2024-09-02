class Solution {
public:
// from course schedule 1
 bool canFinish(int n, vector<vector<int>>& prerequisites) {
     // bi -> ai
     // 0, 1, 2 tricolor dfs
    vector<vector<int>>adj(n);
    for(auto &e:prerequisites){
        adj[e[1]].push_back(e[0]);
    }
    vector<int>vis(n);
     function<int(int)>hasLoop = [&](int x)->int{
        if(vis[x]==1) return true;
        if(vis[x]==2) return false;
        vis[x] = 1;
        for(auto &a:adj[x]){
            if(hasLoop(a)) return true;
        }
        vis[x] = 2;
        return false;
     };
     for(int i = 0;i<n;i++){
        if(hasLoop(i)) return false;
     }
     return true;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prq) {
       if(!canFinish(n,prq)) return {};
       vector<vector<int>>adj(n);
        for(auto &e:prq){
            adj[e[1]].push_back(e[0]);
        }
        vector<int>indegree(n);
        for(auto &e:prq)indegree[e[0]]++;
        vector<int>ans;
        queue<int>q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(q.size()){
            auto f = q.front();
            q.pop();
            for(auto &a:adj[f]){
                indegree[a]--;
                if(indegree[a]==0){
                    ans.push_back(a);
                    q.push(a);
                }
            }

        }
        return ans;
    }
};