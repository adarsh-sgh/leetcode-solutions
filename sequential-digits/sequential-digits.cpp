class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
  vector<int>v;
  for (int digs = 2;digs <= 9;digs++) {
    int maxStart = 9 - digs + 1;
    for (int start = 1;start <= maxStart;start++) {
      string num = string(digs, '.');
      for (int i = 0;i < digs;i++) {
        num[i] = start + i + '0';
      }
      v.push_back(stoi(num));
    }
  }
  // dbg(v);
  auto  it = lower_bound(v.begin(), v.end(), low);
  vector<int>ans;
  for (;it < v.end() && *it <= high;it++) {
    ans.push_back(*it);
  }
  return ans;
}
};