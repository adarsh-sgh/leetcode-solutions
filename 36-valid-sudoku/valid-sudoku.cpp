class Solution {
public:
    int whichGrid(int i, int j){
        return i/3 + 3 * (j / 3);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>>row(9);
        vector<set<char>>col(9);
        vector<set<char>>grid(9);
        for(int i = 0;i< 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.')continue;
                if(row[i].count(board[i][j]))return false;
                if(col[j].count(board[i][j]))return false;
                int gi = whichGrid(i, j);
                if(grid[gi].count(board[i][j])) return false;
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                grid[gi].insert(board[i][j]);
            }
        }
        return true;
    }
};