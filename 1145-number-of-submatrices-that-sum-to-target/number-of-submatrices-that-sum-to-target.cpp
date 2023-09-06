class Solution {
public:
#define dbg(...) 42;

     int numSubmatrixSumTarget(vector<vector<int>>& a, int target) {
  int m = a.size(), n = a[0].size();
  vector<vector<int>>pref(m + 1, vector<int>(n + 1));
  for (int i = 0;i < m;i++) {
    for (int j = 0;j < n;j++) {
      pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + a[i][j];
    }
  }
  dbg(pref);
  auto sum = [&](int i1, int j1, int i2, int j2) {
    i2++;j2++;
    return pref[i2][j2] + pref[i1][j1] - pref[i2][j1] - pref[i1][j2];
    };
  int ans = 0;
  for (int i = 0;i < m;i++) {
    for (int j = i;j < m;j++) {
      unordered_map<int, int>mp = { { 0,1 } };
      for (int k = 0;k < n;k++) {
        int csum = sum(i, 0, j, k);
        dbg(csum, mp[csum - target])
          ans += mp[csum - target];
        mp[csum]++;
      }
    }
  }
  return ans;
}
};