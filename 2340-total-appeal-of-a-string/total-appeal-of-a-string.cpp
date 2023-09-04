class Solution {
public:
#define dbg(...) 42;
    long long appealSum(string s) {
  vector<int>lastIndex(128, -1);
  int n = s.size();
  long long ans = 0;
  for (int i = 0;i < s.size();i++) {
    int lp = i - lastIndex[s[i]];
    int rp = n - i;
    dbg(lp, rp, lp * rp);
    ans += lp * rp;
    lastIndex[s[i]] = i;
  }
  return ans;
}
};