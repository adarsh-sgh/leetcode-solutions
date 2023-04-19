class Solution {
public:
    #define dbg(...) 42;
int scr(string& s, int i, int j) {
  if (i >= j) return 0;
  if (j == i + 1 && s[i] == '(' && s[j] == ')') return 1;
  int o = 0, c = 0;
  dbg(i, j);
  for (int x = i;x <= j;x++) {
    if (s[x] == '(') {
      o++;
    }
    else c++;
    if (o == c) {
      int scrLeft = scr(s, i + 1, x - 1);
      int scrRight = scr(s, x + 1, j);
      dbg(i, x, j, scrLeft, scrRight);
      return (scrLeft ? 2 * scrLeft : 1) + scrRight;
    }
  }
  assert(false);
  return 0;
  if (s[j] == ')' && s[j - 1] == '(') {
    return 1 + scr(s, i, j - 2);
  }
  if (s[i] == '(' && s[i + 1] == ')') {
    return 1 + scr(s, i + 2, j);
  }
  return 2 * scr(s, i + 1, j - 1);
}
int scoreOfParentheses(string s) {
  return scr(s, 0, s.size() - 1);
}
};