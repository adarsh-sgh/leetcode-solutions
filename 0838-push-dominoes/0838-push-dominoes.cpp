class Solution {
public:
#define dbg(...) 42;
   string pushDominoes(string s) {
  int n = s.size();

  vector<int> r(n), l(n);
  r[0] = s[0] == 'R' ? 0 : 1e6;
  for (int i = 1;i < n;i++) {
    if (s[i] == 'L') r[i] = 1e6;
    else if (s[i] == 'R') r[i] = 0;
    else r[i] = r[i - 1] + 1;
  }

  l[n - 1] = s[n - 1] == 'L' ? 0 : 1e6;
  for (int i = n - 2;i >= 0;i--) {
    if (s[i] == 'R') l[i] = 1e6;
    else if (s[i] == 'L') l[i] = 0;
    else l[i] = l[i + 1] + 1;
  }
  for (int i = 0;i < n;i++) {
    l[i] = min(l[i], (int)(1e6));
    r[i] = min(r[i], (int)(1e6));
    if (l[i] < r[i]) {
      s[i] = 'L';
    }
    else if (r[i] < l[i]) {
      s[i] = 'R';
    }
  }
  dbg(r, l);
  return s;
}
};