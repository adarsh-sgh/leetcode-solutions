class Solution {
public:
vector<int>p;
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void Union(int x, int y){
        p[find(x)] = find(y);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
       // atleast n - 1 total edges should be there
       // no. of ops = no. of disconnected clusters -> dsu 
       p.resize(n);
       iota(p.begin(), p.end(), 0);
       if(connections.size() < n - 1) return -1;
       for(auto &c:connections){
           Union(c[0], c[1]);
       }
       int ans = 0;
       for(int i = 0;i< n;i++){
        if(p[i] == i) ans++;
       }
       return ans - 1;
    }
};