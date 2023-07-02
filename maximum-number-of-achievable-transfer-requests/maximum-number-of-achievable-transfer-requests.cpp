class Solution {
public:
   int maximumRequests(int n, vector<vector<int>>& requests) {
  int rn = requests.size();
  int ans = 0;
  for (int i = 0;i < (1 << rn);i++) {
    vector<int>cnt(n);
    for (int j = 0;j < rn;j++) {
      if (i & (1 << j)) {
        cnt[requests[j][0]]--;
        cnt[requests[j][1]]++;
      }
    }
    for (int x = 0;x < cnt.size();x++) {
      if (cnt[x])break;
      if (x == cnt.size() - 1) {
        ans = max(ans, __builtin_popcount(i));
      }
    }
  }
  return ans;
}
};