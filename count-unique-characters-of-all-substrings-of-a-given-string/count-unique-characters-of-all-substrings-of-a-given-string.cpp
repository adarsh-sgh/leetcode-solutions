class Solution {
public:
    #define dbg(...) 42;
int uniqueLetterString(string s) {
  int n = s.size();
  vector<vector<int>>lin(n + 1, vector<int>(26, -1));
  // lin[0][s[0] - 'A'] = 0;
  for (int i = 1;i <= n;i++) {
    for (int j = 0;j < 26;j++) {
      if (s[i - 1] - 'A' == j)lin[i][j] = i - 1;
      else lin[i][j] = lin[i - 1][j];
    }
  }
  int ans = 0, curr = 0;

  for (int i = 0;i < n;i++) {
    curr = curr + i + 1;
    if (lin[i][s[i] - 'A'] != -1) {
      dbg(curr)
        int t = lin[i][s[i] - 'A'];
      int pt = lin[t][s[i] - 'A'];
      dbg(i, t, pt);
      curr -= (t - pt) + t + 1;
      dbg(curr)
    }
    ans += curr;
  }
  return ans;
}
};