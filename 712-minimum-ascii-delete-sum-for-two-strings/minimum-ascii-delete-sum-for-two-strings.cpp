class Solution {
public:
#define dbg(...) 42;
string s,t;
vector<vector<int>>dp;
int mds(int i, int j) {
  if (i == s.size() || j == t.size()) {
    int del = 0;
    while (i < s.size()) del += s[i++];
    while (j < t.size()) del += t[j++];
    return dp[i][j] = del;
  }
  if(dp[i][j] != -1) return dp[i][j];

  if (s[i] == t[j]) {
    return dp[i][j] =  mds(i + 1, j + 1);
  }
  else {
    return dp[i][j] =  min(s[i] + mds(i + 1, j), t[j] + mds(i, j + 1));
  }
  throw "err";
}
int minimumDeleteSum(string s1, string s2) {
  int asum = 0;
  s = s1;t = s2;
  dp.resize(s.size() + 1,vector<int>(t.size()+1,-1));
  return mds(0, 0);
}
};