class Solution {
public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
  stack<int>md;
  int n = heights.size();
  vector<int>ans(n);
  for (int i = 0;i < heights.size();i++) {
    while (!md.empty() && heights[md.top()] < heights[i]) {
      ans[md.top()]++;
      md.pop();
    }
    if (md.size())ans[md.top()]++;
    md.push(i);
  }
  return ans;
}
};