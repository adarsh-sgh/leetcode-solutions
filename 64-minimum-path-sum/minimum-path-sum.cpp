class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       for(int i = 0;i < grid.size();i++){
        for(int j = 0;j< grid[0].size();j++){
            if(i == 0 && j == 0)continue;
            int c1 = i == 0? 1e7:grid[i - 1][j];
            int c2 = j == 0? 1e7 : grid[i][j-1];
            grid[i][j] = min(c1,c2) + grid[i][j];
        }
       } 
       return grid.back().back();
    }
};