class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
  int n = s.size();
  set<string>wd(wordDict.begin(), wordDict.end());
  vector<int>dp(n + 1);
  dp[0] = true;
  for (int i = 1;i <= n;i++) {
    for (int j = 0;j < i;j++) {
      dp[i] = dp[j] &&  wd.count(s.substr(j, i - j));
      if (dp[i]) break;
    }
  }
  return dp.back();
}
};