class Solution {
public:
#define dbg(...) 42;
    string minWindow(string s, string t) {
  vector<int>v(128);
  for (auto&& c : t) v[c]++;
  int start = 0, end = 0, ctr = t.size(), winMin = INT_MAX, stMin = -1;
  // v[start]--;
  if (--v[s[start]] >= 0) ctr--;
  while (start < s.size() && end < s.size()) {
    dbg(start, end, ctr);
    if (ctr <= 0) {
      if (winMin > end - start + 1) {
        winMin = end - start + 1;
        stMin = start;
      }
      if (v[s[start++]]++ >= 0) {
        ctr++;
      }
    }
    else {
      if (--v[s[++end]] >= 0) {
        ctr--;
      };
    }
  }
  if (stMin == -1) return "";
  dbg(stMin, winMin);
  return s.substr(stMin, winMin);

}
};