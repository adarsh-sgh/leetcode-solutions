class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
  int n = nums.size();
  vector<pair<int, int>>v;
  for (int i = 0;i < n;i++) {
    for (auto&& x : nums[i]) {
      v.push_back({ x,i });
    }
  }
  sort(v.begin(), v.end());
  map<int, int>vis;
  int i = 0;
  vector<int>ans{0, (int)1e7};
  for (int j = 0;j < v.size();j++) {
    vis[v[j].second]++;
    while (vis.size() == n) {
      if (ans[1] - ans[0] > v[j].first - v[i].first) {
        ans = { v[i].first,v[j].first };
      }
      vis[v[i].second]--;
      if (vis[v[i].second] == 0) {
        vis.erase(v[i].second);
      }
      i++;
    }
  }
  return ans;

}
};