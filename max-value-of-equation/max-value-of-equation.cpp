class Solution {
public:
    
int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
  // map<int, int>m;
  // multiset<int>m;
  int i = 0;
  int ans = INT_MIN;
  priority_queue<vector<int>>q;
  for (int j = 0;j < points.size();j++) {
    auto x = points[j][0], y = points[j][1];

    // while (points[j][0] - points[i][0] > k) {
    //   i++;
    // }
    while (!q.empty() && x-q.top()[1] > k) q.pop();
    if (q.size())ans = max(ans, x + y + q.top()[0]);
    q.push({ y - x,x });
    // ans = max(ans, points[j][0] - points[i][0] + y1 + y2);
  }
  return ans;
}
};