class Solution {
public:
    vector<int>dir = {-1, 0, 1, 0 , -1};


    void dfs(int x, int y, vector<vector<int>>& grid ){
        // visited check 
        if(grid[x][y] == 2) return;
        int gxy = grid[x][y];
        grid[x][y] = 2;
        auto oob = [&](int x, int y){
            return x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size();
        };
        for(int d = 0; d < 4; d++){
        int xn = x + dir[d], yn = y + dir[d + 1];
        if(oob(xn, yn) || grid[xn][yn] != gxy)continue;
        dfs(xn, yn, grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
       int n = grid.size(), m = grid[0].size(); 
       for(int i = 0; i < n;i++){
        dfs(i, 0, grid);
        dfs(i, m - 1, grid);
       }
       for(int j = 0;j < m;j++){
        dfs(0,j,grid);
        dfs(n-1,j,grid);
       }
       int ans = 0;
       for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
           if(grid[i][j] == 0){
            ans++;
            dfs(i,j, grid);
           }
        }
       }
       return ans;
    }
};