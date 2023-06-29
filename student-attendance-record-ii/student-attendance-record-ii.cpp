class Solution {
public:
    
#define ll long long
int mod = 1e9 + 7;
vector<vector<vector<ll>>>dp;
ll ways(int n, int l, bool absent) {
  if (n == 0)return l == 0;
  if (l < 0 || l > 2)return 0;
  ll& res = dp[n][l][absent];
  if (res != -1) return res;
  res = 0;
  if (l == 0) {
    for (int ab = 0;ab <= min(1, (int)absent);ab++)
      res += ways(n - 1, 0, absent & ab) + ways(n - 1, 1, absent & ab) + ways(n - 1, 2, absent & ab);
  }
  else if (l == 1)  res = ways(n - 1, 0, absent);
  else  res = ways(n - 1, 1, absent);
  return res % mod;
  return res;
}

int checkRecord(int n) {
  dp.resize(n + 1, vector<vector<ll>>(3, vector<ll>(2, -1)));
  int ans = 0;
  for (int i = 0;i < 3;i++) {
    ans += ways(n, i, true);
    ans %= mod;
  }
  return ans;
}
};