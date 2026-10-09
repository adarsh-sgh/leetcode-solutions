class Solution {
     int[] dir = {-1,0,1,0,-1};

    public int numIslands(char[][] grid) {
        int ans = 0;
       for(int i = 0; i < grid.length;i++){
        for(int j = 0 ; j < grid[i].length;j++){
            if(grid[i][j] == '1'){
                ans++;
                dfs(i,j,grid);
            }
        }
       }
       return ans;
       
    }

    private void dfs(int x, int y, char[][] grid){
        if( x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) return;
        if(grid[x][y] == '0') return;
        grid[x][y] = '0';
        for(int d = 0; d < 4; d++){
            dfs(x + dir[d], y + dir[d+1], grid);
        }
        return;
    }
}