class Solution {
public:
    #define dbg(...) 42;
    vector<string> dict;
string s;
int n;
vector<int>dp;
int mer(int l) {
  int ans = n - l;
  if (l >= s.size()) return 0;
  if (dp[l] != -1) return dp[l];
  dbg(l);
  for (auto&& w : dict) {

    for (int i = 0;i < w.size();i++) {
      if (w[i] != s[l + i]) {
        break;
      }
      if (i == w.size() - 1) {
        ans = min(ans, mer(l + w.size()));
      }
    }
  }
  ans = min(ans, 1 + mer(l + 1));
  dp[l] = ans;
  return ans;
}
int minExtraChar(string S, vector<string>& dictionary) {
  s = S;
  n = s.size();
  dict = dictionary;
  dp.resize(n, -1);
  // dp.resize(n, vector<int>(n, -1));
  return mer(0);

}
};