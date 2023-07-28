class Solution {
public:
    vector<vector<double>>grid;
    int inf = 1e6;
    int h = 1e-6;
    int dala;
    double kitnaMilega(int i,int j){
        if(i<0||j<0||i>=100||j>=100)return 0;
        if(i==0 && j==0) return dala;
        if(grid[i][j] != -1){
            return grid[i][j];
        }
        return grid[i][j] = max((kitnaMilega(i-1,j-1) - 1)/2,(double)0) + max((kitnaMilega(i-1,j) -1)/2,(double)0);
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        grid.resize(101,vector<double>(101,-1));
        dala = poured;
        return min(kitnaMilega(query_row,query_glass),1.0);
    }
};