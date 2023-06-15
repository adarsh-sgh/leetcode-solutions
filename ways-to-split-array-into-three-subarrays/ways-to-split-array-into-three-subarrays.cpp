#define dbg(...) 42;
class Solution {
public:
  int mod = 1e9 + 7;
    int waysToSplit(vector<int>& nums) {
  int n = nums.size();
  vector<int>pref(n);
  pref[0] = nums[0];
  for (int i = 1;i < n;i++) {
    pref[i] = pref[i - 1] + nums[i];
  }
  long long ans = 0;
  dbg(pref)
    for (int j = 0;j < n-1;j++) {
      int lower = 2 * pref[j] - pref.back();
      int upper = (pref[j]) / 2;
      if (lower > upper) continue;
      auto lu = lower_bound(pref.begin(), pref.begin() + j, lower) - pref.begin();
      auto ul = upper_bound(pref.begin(), pref.begin() + j, upper) - pref.begin();
      dbg(j, pref[j], lu, ul, lu - ul, lower, upper);
      ans += ul - lu;
      ans %= mod;
    }
  return ans;
}
};