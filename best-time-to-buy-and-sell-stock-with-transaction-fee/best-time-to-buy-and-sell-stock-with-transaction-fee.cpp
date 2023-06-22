class Solution {
public:
    vector<pair<int, int>>dp;
vector<int> p;
int f;

int mp(int i, bool own) {
  if (i >= dp.size()) return 0;
  int& dpv = own ? dp[i].first : dp[i].second;
  if (dpv != -1) return dpv;
  if (own) return dpv = max(mp(i + 1, own), mp(i + 1, false) + p[i]);
  else return dpv = max(mp(i + 1, false), -p[i] - f + mp(i + 1, true));
  assert(false);
  return -1;
}
int maxProfit(vector<int>& prices, int fee) {
  p = prices;
  f = fee;
  dp.resize(p.size(), pair<int, int>(-1, -1));
  return mp(0, false);
}
};