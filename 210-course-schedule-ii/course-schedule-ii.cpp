class Solution {
public:
// bfs approach
    vector<int> findOrder(int nc, vector<vector<int>>& pr) {
     vector<int>indegree(nc);
     vector<vector<int>>adj(nc);
     for(auto &x:pr){
        indegree[x[0]]++;
        adj[x[1]].push_back(x[0]);
     }
     queue<int>q;
     for(int i = 0;i < nc;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
     }
     vector<int>ans;
     while(q.size()){
        int t = q.front();
        ans.push_back(t);
        q.pop();
        for(auto &a:adj[t]){
            if(--indegree[a] == 0){
                q.push(a);
            }
        }
     }
     if(ans.size() != nc) return {};
    return ans;
    

    }
};