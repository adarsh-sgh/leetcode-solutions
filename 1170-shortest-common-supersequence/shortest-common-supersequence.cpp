class Solution {
public:
   
string lcs(string& s1, string& s2) {
  vector<vector<string>>dp(s1.size() + 1, vector<string>(s2.size() + 1));
  dp[0][0] = "";
  for (int i = 0;i < s1.size();i++) {
    for (int j = 0;j < s2.size();j++) {
      // dp[i+1][j+1] 
      if (s1[i] == s2[j]) {
        dp[i + 1][j + 1] = dp[i][j] + s1[i];
      }
      else {
        dp[i + 1][j + 1] = dp[i][j + 1].size() > dp[i + 1][j].size() ? dp[i][j + 1] : dp[i + 1][j];
      }
    }
  }
  return dp.back().back();
}


string shortestCommonSupersequence(string str1, string str2) {
  string lc = lcs(str1, str2);
  int i = 0, j = 0;
  // dbg(lc);
  string res;
  for (auto&& c : lc) {
    while (str1[i] != c) res += str1[i++];
    while (str2[j] != c) res += str2[j++];
    res += c;
    i++;
    j++;
  }
  for (;i < str1.size();i++)res += str1[i];
  for (;j < str2.size();j++)res += str2[j];
  return res;
}
};