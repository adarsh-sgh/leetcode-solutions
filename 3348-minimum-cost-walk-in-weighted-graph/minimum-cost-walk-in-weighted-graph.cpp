class Solution {
public:
    vector<int>p,a;
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    void Union(int x,int y){
        // a[find(y)] &= a[find(x)];
        p[find(x)] = find(y);
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    //   vector<int>p(n),a(n);
    p.resize(n);a.resize(n);
    for(int i = 0;i<n;i++){
            p[i] = i;
            a[i] = (1ll<<29) - 1;
    }

    for(auto &e:edges){
       auto u = e[0], v = e[1], w = e[2];
        Union(u,v);
        // a[find(u)] &= w;
    }
    for(auto &e:edges){
       auto u = e[0], v = e[1], w = e[2];
        a[find(u)] &= w;
    }

    vector<int>ans;
    for(auto &q:query){
        if(q[0] == q[1]){
            ans.push_back(0);
        }
        else if(find(q[0]) == find(q[1])){
            ans.push_back(a[find(q[0])]);
        }else{
            ans.push_back(-1);
        }
    }
    return ans;
    }
};