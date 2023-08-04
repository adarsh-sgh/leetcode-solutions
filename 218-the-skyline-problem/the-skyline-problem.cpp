class Solution {
public:
    
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

  vector<vector<int>>points;
  for (auto&& b : buildings) {
    points.push_back({ b[0],-b[2] });
    points.push_back({ b[1],b[2] });
  }
  // neg height -> start
  sort(points.begin(), points.end());

  multiset<int>ms{ 0 };
  vector<vector<int>>ans;
  for (int i = 0;i < points.size();i++) {
    int ch = points[i][1];
    auto maxh = *ms.rbegin();
    if (ch < 0) {
      ms.insert(-ch);
    }
    else {
      ms.erase(ms.find(ch));
    }
    if (*ms.rbegin() != maxh) {
      ans.push_back({ points[i][0],*ms.rbegin() });
    }
  }
  return ans;
}
};