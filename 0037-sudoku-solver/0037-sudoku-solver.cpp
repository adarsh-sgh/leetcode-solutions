class Solution {
public:
#define dbg(...) 42; 
vector<vector<int>>row, col, gr;
void fillb(vector<vector<char>>& b) {
  for (int i = 0;i < 9;i++) {
    for (int j = 0;j < 9;j++) {
      // dbg(i, j, b[i][j]);
      if (b[i][j] == '.') continue;
      // dbg(i, j, b[i][j] - '0');
      // if (row[i][b[i][j] - '0']) return false;
      row[i][b[i][j] - '0'] = true;
      // if (col[j][b[i][j] - '0']) return false;
      col[j][b[i][j] - '0'] = true;
      int gri = (i / 3) * 3 + j / 3;
      // dbg(gri, i, j, b[i][j] - '0');
      // if (gr[gri][b[i][j] - '0']) return false;
      gr[gri][b[i][j] - '0'] = true;
    }
  }
  // return true;
}
bool isValid(int i, int j, int c) {
  int gri = (i / 3) * 3 + j / 3;
  return !(row[i][c] || col[j][c] || gr[gri][c]);
}
vector<vector<char>>bo, b;
bool solve(int n) {
  int x = n / 9;
  int y = n % 9;
  dbg(n, x, y);
  dbg(x, y);
  // dbg(x, y, b[x][y], bo[x][y]);
  if (n > 80) return true;
  if (bo[x][y] != '.') return solve(n + 1);
  for (int i = 1;i <= 9;i++) {
    // bool val = isValid(b);
    bool val = isValid(x, y, i);
    if (!val) continue;
    int gri = (x / 3) * 3 + y / 3;
    row[x][i] = true;col[y][i] = true;gr[gri][i] = true;
    b[x][y] = '0' + i;
    if (!solve(n + 1)) {
      b[x][y] = '.';
      row[x][i] = false;col[y][i] = false;gr[gri][i] = false;
      continue;
    }


    return true;
    // if (isValid(b) && solve(n + 1)) return true;
  }
  return false;
}

void solveSudoku(vector<vector<char>>& board) {
  bo = board;
  b = board;
  row.resize(10, vector<int>(10));
  col.resize(10, vector<int>(10));
  gr.resize(10, vector<int>(10));
  fillb(b);
  solve(0);
  board = b;
}
};