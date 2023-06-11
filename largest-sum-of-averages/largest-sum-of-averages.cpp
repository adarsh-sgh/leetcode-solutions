class Solution {
public:
#define dbg(...) 42;
    vector<vector<double>>dp;
vector<int>pref;
int n;
double lsa(int i, int k) {
  if (dp[i][k] != -1)return dp[i][k];
  if (k <= 0) return 0;
  if (i >= n)return 0;
  if (k == 1) {
    return dp[i][k] = (1.0 * (pref[n] - pref[i])) / (n - i);
  }
  // for (int i = n - 1;i >= 0;i--) {
    // for (int j = 1;j <= k;j++) {
  double ans = 0;
  for (int x = i;x < n;x++) {
    int sumix = pref[x + 1] - pref[i];
    double favg = (1.0 * sumix) / (x - i + 1);
    ans = max(ans, favg + lsa(x + 1, k - 1));
    if (i == 5) { dbg(ans, sumix, i, x, favg); }

  }
  return  dp[i][k] = ans;
}
double largestSumOfAverages(vector<int>& nums, int k) {
  n = nums.size();
  vector<vector<double>>pp(n + 1, vector<double>(n + 1, -1));
  dp = pp;
  pref.resize(n + 1);
  for (int i = 0;i < n;i++) {
    pref[i + 1] = pref[i] + nums[i];
  }
  // dbg(pref);
  // lsa(0, k);
  // cout << dp;
  // dbg(dp);
  return lsa(0, k);
}
};