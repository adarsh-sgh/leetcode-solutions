class Solution {
public:
    int ms(vector<int>& v) {
  int n = (v.size() + 1) / 3;
  int m = v.size();
  vector<vector<int>>dp(m + 1, vector<int>(n + 1));

  for (int i = 1;i <= m;i++) {
    if (i == 1) { dp[i][1] = max(dp[i][1], v[i - 1]);continue; }
    for (int j = 1;j <= n;j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + v[i - 1]);
    }
  }
  return dp.back().back();
}

int maxSizeSlices(vector<int>& slices) {
  int b = slices.back();
  slices.pop_back();
  vector<int>v1 = slices;
  slices.erase(slices.begin());
  slices.push_back(b);
  return max(ms(v1), ms(slices));
}

};