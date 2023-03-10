class Solution {
public:
#define dbg(...) 3;
    int minFlipsMonoIncr(string s){
  int n = s.size();
  vector<int>pref(n + 1);

  for (int i = 1;i <= n;i++) {
    pref[i] = pref[i - 1] + s[i - 1] - '0';
  }
  dbg(pref);
  int ans = INT_MAX;
  for (int i = 0;i <= n;i++) {
    // 0 upto i and 1 afterwards
    int cost = pref[i] + n - i - (pref[n] - pref[i]);
    ans = min(ans, cost);
  }
  ans = min(ans, pref[n]);
  return ans;
}
};