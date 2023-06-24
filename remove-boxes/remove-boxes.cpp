class Solution {
public:
#define dbg(...) 42;
vector<vector<vector<int>>>dp;
vector<pair<int, int>>v;
int n;
int rb(int i, int j, int k) {
  if (i > j) return 0;
  assert(k < n && k >= 0 && i < n && i >= 0 & j < n && j >= 0);
  k += v[i].second;
  if (dp[i][j][k] != -1) return dp[i][j][k];
  int res = k * k + rb(i + 1, j, 0);
  for (int x = i + 1; x <= j;x++) {
    if (v[x].first == v[i].first)res = max(res, rb(i + 1, x - 1, 0) + rb(x, j, k));
  }
  // dbg(i, j, k, res);
  if (dp[i][j][k] != -1 && dp[i][j][k] != res) {
    dbg(i, j, k, res, dp[i][j][k]);
  }
  return dp[i][j][k] = res;
}
int removeBoxes(vector<int>& boxes) {
  n = boxes.size();
  dp.resize(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
  // dbg(dp);
  for (int i = 0;i < boxes.size();i++) {
    if (v.empty() || v.back().first != boxes[i])v.push_back({ boxes[i],1 });
    else v.back().second++;
  }
  // dbg(v);
  return rb(0, v.size() - 1, 0);
}
};