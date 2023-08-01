class Solution {
public:
#define dbg(...) 42;
    vector<int>minl;
int minSumOfLengths(vector<int>& arr, int target) {
  int n = arr.size();
  vector<int>pref(n + 1);
  for (int i = 1;i <= n;i++)pref[i] = pref[i - 1] + arr[i - 1];
  int sl = n + 1;
  map<int, int>m;
  vector<int>v1(n + 1, n + 1);
  for (int i = 0;i <= n;i++) {
    if (m.count(pref[i] - target))sl = min(sl, i - m[pref[i] - target]);
    v1[i] = sl;
    m[pref[i]] = i;
  }
  sl = n + 1;
  m.clear();
  dbg(v1);
  int ans = n + 1;
  for (int i = n;i >= 0;i--) {
    if (m.count(pref[i] + target))sl = min(sl, m[pref[i] + target] - i);
    dbg(sl, i, v1[i]);
    ans = min(ans, sl + v1[i]);
    m[pref[i]] = i;
  }
  return ans > n ? -1 : ans;
}
};