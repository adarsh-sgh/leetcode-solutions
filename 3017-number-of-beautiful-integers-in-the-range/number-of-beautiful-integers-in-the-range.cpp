class Solution {
public:
    #define dbg(...) 42;
 int k;
int dp[10][10][10][21][2][2];
int nbi(const string& s, int i, bool tight, bool started, int even, int odd, int rem) {
  if (i == s.size()) {
    bool gg = even == odd && rem == 0;
    if (gg) {
      dbg(s, gg, even, odd, rem)
    }
    return gg;
  }
  dbg(i, tight, even, odd, rem)

    int ub = tight ? s[i] - '0' : 9;
  int& res = dp[i][even][odd][rem][tight][started];
  if (res != -1) return res;
  res = 0;
  for (int j = 0;j <= ub;j++) {
    if (!started && j == 0) {
      res += nbi(s, i + 1, tight && j == s[i] - '0', false, 0, 0, 0);
    }
    else res += nbi(s, i + 1, tight && j == s[i] - '0', true, even + !(j % 2), odd + (j % 2), (rem * 10 + j) % k);
  }
  return res;
}
int numberOfBeautifulIntegers(int low, int high, int K) {
  k = K;
  memset(dp, -1, sizeof(dp));
  int nh = nbi(to_string(high), 0, 1, 0, 0, 0, 0);
  int nl = 0;
  memset(dp, -1, sizeof(dp));
  nl = nbi(to_string(low - 1), 0, 1, 0, 0, 0, 0);
  dbg(nh, nl);
  return nh - nl;
}
};