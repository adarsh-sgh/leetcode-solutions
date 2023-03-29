class Solution {
public:
#define dbg(...) 42;
   vector<int>dp;
int n;

vector<int>c, d;
int cost(int i) {
  if (i >= n) return 0;
  if (dp[i] != -1) return dp[i];
  vector<int>days = { 1,7,30 };
  int cst = INT_MAX;
  dbg(i);
  for (int j = 0;j < 3;j++) {
    // d[j] + 1, d[j] + 7
    auto x = lower_bound(d.begin(), d.end(), d[i] + days[j]) - d.begin();
    dbg(x, i, j, cst);
    // if (x >= n) cst = 0;
    cst = min(cst, c[j] + cost(x));
  }
  dp[i] = cst;
  return cst;
  // return min((c[0] + cost(i + 1)), min(c[1] + cost(i + 7), c[2], cost(i + 30)));
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
  n = days.size();
  dp.resize(n, -1);
  c = costs; d = days;

  int ans = cost(0);
  dbg(dp);
  return ans;
}
};