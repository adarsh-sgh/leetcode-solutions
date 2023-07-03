class Solution {
public:
vector<vector<vector<int>>>dp;

int ways(string& s, int i, bool strict, bool oneAllowed) {
  if (i == s.size())return 1;
  auto& res = dp[i][strict][oneAllowed];
  // 0 at curr pos
  if(res != -1) return res;
  res = ways(s, i + 1, strict && (s[i] == '0'), true);
  //1 at i
  if (!oneAllowed) return res;
  if (!strict || (s[i] == '1')) res += ways(s, i + 1, strict, false);
  return res;
}
int findIntegers(int n) {
  string bin;

  for (int i = 31;i >= 0;i--) {
    if (n & (1 << i))bin += '1';
    else bin += '0';
  }
  dp.resize(32, vector<vector<int>>(2, vector<int>(2, -1)));
//   dbg(bin);
  return ways(bin, 0, true, true);
}
};