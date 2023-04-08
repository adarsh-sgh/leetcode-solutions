class Solution {
public:
    vector<vector<int>> t;
    map<pair<int,int>,int>m;
    int dfs(int x,int y){
        if(m.count({x,y})) return m[{x,y}];
        if(x >= t.size()) return 0;
        m[{x,y}] =  t[x][y] + min(dfs(x+1,y), dfs(x+1,y+1));
        return m[{x,y}];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        t = triangle;
        return dfs(0,0);
    }
};