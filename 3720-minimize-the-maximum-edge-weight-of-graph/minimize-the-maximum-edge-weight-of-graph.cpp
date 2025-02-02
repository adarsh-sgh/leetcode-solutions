class Solution {
public:

    vector<int>p;
    int find(int x){
       if(p[x] == x) return x;
       return p[x] = find(p[x]);
    }

    void Union(int x,int y){
        p[find(x)] = find(y);
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
       // if multiple edges from a to b only smallest wt edge matters
       // can we use binary search on wt threshold ? let's try

    //  sort(edges.begin(), edges.end(), [](auto e1, auto e2){
    //    return e1[2] < e2[2];
    //  });
    //  p.resize(n);
    vector<int>vis(n);
    vector<vector<array<int,2>>>radj(n);
    int thr = -1;
    function<void(int)> dfs = [&](int x){
        if(vis[x]) return;
        vis[x] = 1;
        for(auto &a:radj[x]) {
            if(a[1] <= thr) dfs(a[0]);
        }
      };
      for(auto &e:edges){
        radj[e[1]].push_back({e[0], e[2]});
      }

      auto good = [&](int wt){        
        // outgoing edges
        // vector<int>og(n);
        // radj.clear();
        // radj.resize(n);
        // for(auto &e:edges){
        //     if(e[2] > wt) continue;
        //     // if(og[e[0]]++ >= threshold) continue;
        //     radj[e[1]].push_back(e[0]);
        // }
        for(auto &x:vis) x = 0;
        thr = wt;
        dfs(0);
        for(auto &x:vis) if(!x) return false;
        return true;
      };

     int l = 0, r = 0;
     for(auto &e:edges){
        r = max(r, e[2]);
     }
     while(l < r){
        int m = (l+r)>>1;
        if(good(m)){
            r = m;
        }else{
            l = m + 1;
        }
     }
     if(!good(l)) return -1;
     return l;
    }
};