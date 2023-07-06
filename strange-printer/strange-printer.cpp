class Solution {
public:
    
string s;
vector<vector<int>>dp;
int sp(int i, int j) {
  if (i > j)return 0;
  int& res = dp[i][j];
  if (res != -1)return res;
  res = sp(i + 1, j) + 1;
  for (int x = i + 1;x <= j;x++) {
    if (s[x] == s[i]) { res = min(sp(i + 1, x - 1) + sp(x, j), res); }
  }
  return res;
}

int strangePrinter(string S) {
  for (auto&& c : S) {
    if (s.empty() || s.back() != c)s.push_back(c);
  }
  dp.resize(s.size(), vector<int>(s.size(), -1));
  return sp(0, s.size() - 1);
}
};