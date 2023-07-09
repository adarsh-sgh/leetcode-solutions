class Solution {
public:
#define dbg(...) 42;
   string s;
int inf = 101;
unordered_map<int, unordered_map<int, unordered_map<int, int>>>dp;
int pp(int i, int j, int k) {

  if (j - i + 1 < k) return inf;
  if (j - i + 1 == k) return 0;
  if (dp[i][j].count(k))return dp[i][j][k];
  int& res = dp[i][j][k];
  if (k == 1) {
    for (int o = 0;o < (j - i + 1) / 2;o++)res += s[i + o] != s[j - o];
    return res;
  }
  assert(i == 0);
  res = inf;
  for (int x = i;x <= j;x++)res = min(res, pp(i, x, k - 1) + pp(x + 1, j, 1));
  dbg(i, j, k, res);
  return res;
}

int palindromePartition(string S, int k) {
  s = S;
  return pp(0, s.size() - 1, k);
}
};