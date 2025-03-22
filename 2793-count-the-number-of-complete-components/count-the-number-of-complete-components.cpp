class Solution {
public:

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
       vector<int>p(n);
       for(int i = 0;i< n;i++)p[i] = i;
       function<int(int)> find = [&](int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
       };

       auto Union = [&](int x, int y){
        p[find(x)] = find(y);
       }; 
       // count how many edges a node is connected to
       vector<int>cnt(n);
       map<int,set<int>>mp;

       for(auto &e:edges){
        Union(e[0], e[1]);
        cnt[e[0]]++;
        cnt[e[1]]++;
       }

       for(int i = 0;i<n;i++){
        mp[find(i)].insert(i);
       }

       int ans = 0;
       
       for(auto &[k,v]:mp){
        bool gg = true;
        for(auto &x:v){
            if(cnt[x] != v.size() - 1){
                gg = false;
            }
        }
        ans += gg;
       }

       return ans;
    }
};