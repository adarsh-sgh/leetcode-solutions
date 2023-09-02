class Solution {
public:
int mod = 1e9 + 7;
   int numberOfArrays(string s, int k) {
  int n = s.size();
  vector<int>dp(n + 1);
  dp[0] = 1;
  for (int i = 0;i < s.size();i++) {
    if (s[i] == '0')continue;
    long long num = 0;
    for (int j = i;j < min(i + 10, n);j++) {
      num = num * 10 + s[j] - '0';
      if (num > k)break;
      dp[j + 1] += dp[i];
      dp[j+1] %= mod;
    }
  }
  return dp.back();
}
};