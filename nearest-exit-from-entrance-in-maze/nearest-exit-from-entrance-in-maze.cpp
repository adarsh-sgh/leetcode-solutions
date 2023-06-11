class Solution {
public:
   
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
  queue<pair<int, int>>q;
  vector<int>dir = { -1,0,1,0,-1 };
  q.push({ entrance[0],entrance[1] });
  maze[entrance[0]][entrance[1]] = '+';
  int dis = 0;
  while (!q.empty()) {
    int n = q.size();
    while (n--) {
      auto [x, y] = q.front();q.pop();
      // dbg(x, y);
      for (int d = 0;d < 4;d++) {
        int xn = x + dir[d], yn = y + dir[d + 1];
        if ((xn < 0 || yn < 0 || xn >= maze.size() || yn >= maze[0].size())) {
          // dbg("OOB", xn, yn, dis);
          if (dis == 0) {
            continue;
          }
          else {
            return dis;
          }
        }
        // dbg(xn, yn, maze[xn][yn]);
        if (maze[xn][yn] == '+')continue;
        maze[xn][yn] = '+';
        q.push({ xn,yn });
      }
    }
    dis++;
  }
  // cout << maze << endl;
  return -1;
}
};