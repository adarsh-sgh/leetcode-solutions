class Solution {
public:
int mod = 1e9+7;
    int distinctSubseqII(string s) {
  vector<int>prv(128);
  int n = s.size();
  //dp[i] -> distinct subseqs ending at i not counted before
  vector<int>dp(n);
  dp[0] = 1;
  vector<int>dpp(n+1);
  dpp[1] = 1;
  for (int i = 1;i < s.size();i++) {
    char c = s[i];
    int pi = prv[s[i]];
    if (s[pi] != s[i])dp[i] = 1;
    // for (int j = pi;j < i;j++) {
    //   dp[i] += dp[j];
    //   dp[i] %= mod;
    // }
    dp[i] += (mod  + dpp[i] - dpp[pi]) % mod;
    dpp[i+1] = (dpp[i] + dp[i]) % mod;
    prv[s[i]] = i;
  }
//   dbg(dp);
  int ans = 0;
  for (int i = 0;i < n;i++){
    ans += dp[i];
    ans %= mod;
    }
  return ans;
}
};