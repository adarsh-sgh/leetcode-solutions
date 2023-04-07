class Solution {
public:
#define dbg(...) 1;
   map<int, vector<string>>mp;
bool isp(string s1, string s2) {
  assert(s1.size() + 1 == s2.size());
  int i2 = 0;
  for (int i = 0;i < s1.size();i++) {
    if (i2 > s2.size()) return false;
    if (s2[i2] != s1[i]) {
      i2++;
      if (s2[i2] != s1[i]) return false;
    }
    i2++;
  }
  return true;
}
map<string, int>dp;
int lsc(string s1) {
  int n = s1.size();
  if (dp.count(s1)) return dp[s1];
  assert(isp("htc", "hrtc") == true);
  int ans = 1;
  for (auto&& x : mp[n - 1]) {
    if (isp(x, s1)) {
      ans = max(ans, 1 + lsc(x));
    }
  }
  dp[s1] = ans;
  return ans;
}

int longestStrChain(vector<string>& words) {
  for (auto&& x : words) {
    mp[x.size()].push_back(x);
  }
  dbg(mp);
  int ans = 1;
  for (auto&& x : words) {
    ans = max(ans, lsc(x));
  }
  return ans;
}
};