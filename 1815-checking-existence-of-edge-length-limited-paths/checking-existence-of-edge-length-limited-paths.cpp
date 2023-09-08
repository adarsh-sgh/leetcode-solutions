class Solution {
public:
    vector<int>parent;
    int find(int i ){
        if(parent[i]==i) return i;
        return parent[i] = find(parent[i]);
    }
    void Union(int a,int b){
        parent[find(a)] = find(b);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        for(int i = 0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[](auto &a,auto &b){
            return a[2] < b[2];
        });
        sort(edgeList.begin(),edgeList.end(),[](auto &a,auto &b){
            return a[2] < b[2];
        });
        int ei = 0;
        vector<bool>ans(queries.size());
        for(int i = 0;i<queries.size();i++){
            auto &q = queries[i];
            int lim = q[2];
            for(;  ei < edgeList.size() && edgeList[ei][2] < lim ;ei++){
                Union(edgeList[ei][0],edgeList[ei][1]);
            }
            ans[q[3]] = (find(q[0]) == find(q[1]));
        }
        return ans;
    }
};