class Solution {
public:
vector<int>pref;
int inf = 1e9 + 5;
vector<vector<int>>dp;
int md(int i, int k) {
  if (k < 0) return inf;
  if (i == -1) return 0;
  if (dp[i][k] != -1) return dp[i][k];
  int& res = dp[i][k];
  res = inf;
  for (int j = 0;j <= i;j++) {
    int mi = (j + i) / 2;
    int cover = (pref[i + 1] - pref[mi + 1]) - (pref[mi] - pref[j]);
    if ((j - i) & 1) {
      cover -= (pref[mi + 1] - pref[mi]);
    }
    res = min(res, cover + md(j - 1, k - 1));
  }
  return res;
}
int minDistance(vector<int>& houses, int k) {
  int n = houses.size();
  sort(houses.begin(),houses.end());
  dp.resize(n, vector<int>(k + 1, -1));
  pref.resize(n + 1);
  for (int i = 1;i <= n;i++) {
    pref[i] = pref[i - 1] + houses[i - 1];
  }
  return md(n - 1, k);
}
};