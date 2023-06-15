class Solution {
public:
    int longestWPI(vector<int>& hours) {
  for (auto&& h : hours) {
    if (h > 8)h = 1;
    else h = -1;
  }
  // find longest subarray with positive sum
  map<int, int>fi;
  int ans = 0;
  int sum = 0;
//   dbg(hours);
  for (int i = 0;i < hours.size();i++) {
    sum += hours[i];
    if (sum > 0) {
      ans = i + 1;
    }
    else {
      if (fi.count(sum - 1)) {
        int j = fi[sum - 1];
        ans = max(ans, i - j);
      }
    }
    if (!fi.count(sum)) fi[sum] = i;
  }
  return ans;
}
};