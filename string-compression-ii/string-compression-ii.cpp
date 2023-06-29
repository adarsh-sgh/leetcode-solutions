class Solution {
public:
#define dbg(...) 42;
int len(int n) {
  int ans = 0;
  if (n == 1) return 0;
  while (n) {
    n /= 10;
    ans++;
  }
  return ans;
}
    string v;
int n;
vector<vector<int>>dp;
int minLen(int i, int k) {
  if (k < 0)return v.size();
  if (i >= v.size())return 0;
  int& res = dp[i][k];
  if (res != -1)return dp[i][k];
  res = max(n - i -k,0);
  int maxFreq = 0;
  vector<int>cnt(128);
  for (int j = i;j < n;j++) {
    cnt[v[j]]++;
    maxFreq = max(maxFreq, cnt[v[j]]);
    int kn = k - (j - i + 1 - maxFreq);
    res = min(res, minLen(j + 1, kn) + 1 + len(maxFreq));
  }
  dbg(i, k, res);

  return res;
}
int getLengthOfOptimalCompression(string s, int k) {
  v = s;
  n = v.size();
  dp.resize(n, vector<int>(n+1, -1));
  return minLen(0, k);
}
};