class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end(), [](auto& i1, auto& i2) {
    return i1[1] < i2[1];
    });
  int maxEnd = INT_MIN;
  int ans = 0;
  for (auto&& i : intervals) {
    if (i[0] < maxEnd) {
      ans++;
      continue;
    }
    maxEnd = i[1];
  }
  return ans;
}
};