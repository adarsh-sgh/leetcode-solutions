class Solution {
public:
vector<vector<int>>dp;
vector<int> c;
int mc(int i, int j) {
  if (i > j)return 0;
  assert(i >= 0 && j < c.size());
  if (dp[i][j] != -1) return dp[i][j];
  int res = INT_MAX;
  for (int x = i;x <= j;x++) {
    res = min(res, mc(i, x - 1) + mc(x + 1, j) + c[j + 1] - c[i - 1]);
  }
  // dbg(i, j, res)
    return dp[i][j] = res;
}
int minCost(int n, vector<int>& cuts) {
  dp.resize(104, vector<int>(104, -1));
  cuts.push_back(0);
  cuts.push_back(n);
  c = cuts;
  sort(c.begin(), c.end());
  // dbg(c)
    return mc(1, c.size() - 2);
}
};