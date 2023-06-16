class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
  map<int, int>m;
  for (auto x : barcodes) {
    m[x]++;
  }
  priority_queue<pair<int, int>>q;
  for (auto&& [x, y] : m) {
    q.push({ y,x });
  }
  vector<int>ans;
  while (!q.empty()) {
    auto t = q.top();
    q.pop();
    if (ans.empty() || ans.back() != t.second) {
      ans.push_back(t.second);
      if (--t.first) {
        q.push(t);
      }
      continue;
    }
    auto t2 = q.top();q.pop();
    q.push(t);
    ans.push_back(t2.second);
    if (--t2.first) {
      q.push(t2);
    }
  }
  return ans;
}
};