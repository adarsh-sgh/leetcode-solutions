class Solution {
public:
// 3 1, 3 2 2 
#define dbg(...) 42;
    int maximalRectangle(vector<vector<char>>& matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  vector<vector<int>> h(m, vector<int>(n));
  for (int i = 0;i < n;i++) {
    h[0][i] = matrix[0][i] - '0';
  }
  for (int i = 1;i < m;i++) {
    for (int j = 0;j < n;j++) {
      if (matrix[i][j] == '0') h[i][j] = 0;
      else h[i][j] = h[i - 1][j] + 1;
    }
  }
  dbg(h);
  int maxArea = 0;
  for (int i = 0;i < m;i++) {
    stack<int>mi;
    vector<int>pse(n, -1);
    vector<int>nse(n, n);
    for (int j = 0;j < n;j++) {
      while (!mi.empty() && h[i][mi.top()] >= h[i][j]) {
        auto t = mi.top();
        nse[t] = j;
        mi.pop();
      }
      if (!mi.empty()) {
        pse[j] = mi.top();
      }

      mi.push(j);
    }
    dbg(nse, pse);
    for (int j = 0;j < n;j++) {
      maxArea = max(maxArea, (nse[j] - pse[j] - 1) * h[i][j]);
    }
  }
  return maxArea;
}
};