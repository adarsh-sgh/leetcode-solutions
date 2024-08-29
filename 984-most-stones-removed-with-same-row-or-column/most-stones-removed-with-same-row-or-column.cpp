class Solution {
public:
    vector<int>p;
    int find(int x){
        if(p[x] == x) return x;
        else return find(p[x]);
    }

    void Union(int x,int y){
        p[find(x)] = find(y);
    }

    int removeStones(vector<vector<int>>& s) {
        int n = s.size();
        vector<array<int,3>>stones;
        for(int i = 0;i<n;i++)stones.push_back({s[i][0], s[i][1],i});
        // int n = stones.size();
        p.resize(n);
        for(int i = 0;i<n;i++){
            p[i] = i;
        }     

        sort(stones.begin(),stones.end());
        for(int i = 1;i<n;i++){
            if(stones[i][0] == stones[i-1][0]) Union(stones[i][2],stones[i-1][2]);
        }
        sort(stones.begin(),stones.end(),[](auto x, auto y) {
            if(x[1] == y[1]) return false;
            return x[1] < y[1];
        });
        for(int i = 1;i<n;i++){
            if(stones[i][1] == stones[i-1][1]) Union(stones[i][2],stones[i-1][2]);
        }
        int lc = 0;
        for(int i = 0;i<n;i++) lc += (p[i] == i);
        return n - lc;
    }
};