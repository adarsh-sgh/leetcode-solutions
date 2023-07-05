class Solution {
public:
#define dbg(...) 42;
    vector<char>digs;string nf;
vector<vector<vector<int>>>dp;
int amn(int i, bool tight, bool start) {
  if (i >= nf.size())return 1;
  int& res = dp[i][tight][start];
  // if (res != -1) return res;
  res = 0;
  if (start) res += amn(i + 1, false, true);
  if (!tight) return res += digs.size() * amn(i + 1, false, false);
  auto lb = lower_bound(digs.begin(), digs.end(), nf[i]);
  if (lb != digs.end() && (*lb) == nf[i]) {
    res += amn(i + 1, tight, false);
  }
  int sm = lb - digs.begin();
  dbg(sm);
  res += amn(i + 1, false, false) * sm;
  return res;
}

int atMostNGivenDigitSet(vector<string>& digits, int N) {
  for (auto&& d : digits) digs.push_back(d[0]);
  nf = to_string(N);
  dbg(nf, digs);
  dp.resize(nf.size(), vector<vector<int>>(2, vector<int>(2, -1)));
  return amn(0, true, true) - 1;
}
};