class Solution {
public:
  static bool firstSmaller(vector<int>& a, vector<int>& b) {
    if(a==b) return false;
    return fls(a,b);
}
static bool fls(vector<int>& a, vector<int>& b) {
  return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
}

int maxHeight(vector<vector<int>>& cuboids) {
  for (auto& c : cuboids)sort(c.begin(), c.end());
  sort(cuboids.begin(), cuboids.end());
  int n = cuboids.size();
  vector<int>dp(n);
  for (int i = 0;i < n;i++) {
    int mxh = 0;
    for (int j = 0;j < i;j++) {
      if (fls(cuboids[j], cuboids[i]))mxh = max(mxh, dp[j]);
    }
    dp[i] = cuboids[i][2] + mxh;
  }
  return *max_element(dp.begin(), dp.end());
}
};