class Solution {
public:
    #define dbg(...) 42;
int totalStrength(vector<int>& strength) {
  stack<int>mi;
  int n = strength.size();
  vector<int>nse(n, n);
  vector<int>pse(n, -1);
  for (int i = 0;i < strength.size();i++) {
    while (mi.size() && strength[i] < strength[mi.top()]) {
      nse[mi.top()] = i;
      mi.pop();
    }
    if (mi.size()) pse[i] = mi.top();
    mi.push(i);
  }
  dbg(nse, pse);
  vector<long long>pref(n + 1), ppref(n + 2);
  long long mod = 1e9 + 7;
  for (int i = 0;i < n;i++) {
    pref[i + 1] = pref[i] + strength[i];
    // pref[i + 1] %= mod;
  }
  for (int i = 0;i <= n;i++) {
    ppref[i + 1] = pref[i] + ppref[i];
    // ppref[i + 1] %= mod;
  }
  dbg(ppref);
  long long ans = 0;
  for (int i = 0;i < n;i++) {
    int l = pse[i] + 1;
    int r = nse[i] - 1;
    dbg(l, r);
    // assert(l < r);
       ans += (1ll * (i - l + 1) * ((ppref[r + 2] - ppref[i + 1])%mod) + 2 * mod - 1ll * (r - i + 1) * ((ppref[i + 1] - ppref[l])%mod)) % mod * strength[i];

    ans %= mod;
    dbg(ans);
  }
  return ans % mod;
}
};