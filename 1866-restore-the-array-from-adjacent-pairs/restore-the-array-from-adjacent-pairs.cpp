class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
       map<int,vector<int>>adj;
       for(auto &p:adjacentPairs){
           adj[p[0]].push_back(p[1]);
           adj[p[1]].push_back(p[0]);
       } 
       int curr =  -1;
        for(auto &[k,v]:adj){
            if(v.size()==1){
                curr = k;
                break;
            }
        }
        vector<int>ans;
        int n = adj.size();
        int prev = -1;
       while(ans.size() != n){
           ans.push_back(curr);
           for(auto &a:adj[curr]){
               if(a==prev)continue;
               prev = curr;
               curr = a;
               break;
           }
       }
        return ans;
    }
};