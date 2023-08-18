class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
     vector<set<int>>adj(n);
     for(auto &&r:roads){
         adj[r[0]].insert(r[1]);
         adj[r[1]].insert(r[0]);
     }   
     int ans = 0;
     for(int i = 0;i<n;i++){
         for(int j = i+1;j<n;j++){
             int curr = adj[i].size() + adj[j].size() - adj[i].count(j);
             ans = max(ans,curr);
         }
     }
     return ans;

    }
};