class Solution {
public:
#define dbg(...) 42;
    int largestRectangleArea(vector<int>& heights) {
  int n = heights.size();
  vector<int>pse(n, -1);
  vector<int>nse(n, n);
  stack<int>mi;
  dbg(heights);
  for (int i = 0;i < n;i++) {
    while (!mi.empty() && heights[mi.top()] > heights[i]) {
      nse[mi.top()] = i;
      mi.pop();
    }
    if (!mi.empty()) pse[i] = mi.top();
    mi.push(i);
  }
  dbg(nse, pse);
  int ans = INT_MIN;
  for (int i = 0;i < n;i++) {
    ans = max(ans, (heights[i] * (nse[i] - pse[i] - 1)));
  }
  return ans;

}
};