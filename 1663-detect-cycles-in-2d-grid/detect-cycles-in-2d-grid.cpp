class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
       // use dfs, if same color happens again it's a cycle
       vector<int>dir = {-1,0,1,0,-1};
       // '.' => visited
       int n = grid.size(), m = grid[0].size();
       bool ans = false;

       auto oob = [&](int x,int y){
        return x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size();
       };
        // make the letters capital once visited
       function<bool(int,int,int, int)>dfs = [&](int x, int y, int xp, int yp)-> bool{
        if(oob(x,y))return false;
        // if capital letter => visited
        if(grid[x][y]  <  'a') return false;
        grid[x][y] += 'A' - 'a';
        bool res = false;
        for(int d = 0; d < 4;d++){
            int xn = x + dir[d], yn = y + dir[d+1];
            if(xn == xp && yn == yp)continue;
            if(oob(xn,yn))continue;
            if(grid[xn][yn] == grid[x][y]) return true;
            if(grid[xn][yn] + 'A' - 'a' != grid[x][y]) continue;
            res = res || dfs(xn, yn, x, y);
        }
        return res;
       };
       for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(dfs(i,j,-1,-1)){
                return true;
            }
        }
       }
       return false;
    }
};