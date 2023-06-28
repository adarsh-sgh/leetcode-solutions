class Solution {
public:
    #define dbg(...) 42;
string minWindow(string s, string t) {
  vector<int>req(128);
  int tdis = 0;
  for (auto&& c : t) {
    if (!req[c])tdis++;
    req[c]++;
  }
  vector<int>curr(128);
  int i = 0;

  int win = 0;
  vector<int>vis(128);
  int minwin = INT_MAX, l = -1, r = -1;
  for (int j = 0;j < s.size();j++) {
    curr[s[j]]++;
    if (req[s[j]] && curr[s[j]] >= req[s[j]] && !vis[s[j]]) {
      vis[s[j]] = true;
      win++;
    }
    while (curr[s[i]] > req[s[i]]) {
      curr[s[i]]--;
      i++;
    }
    dbg(win, i, j);
    if (win == tdis) {
      if (j - i + 1 < minwin) {
        minwin = j - i + 1;
        l = i;
        r = j;
      }
    }

  }
  dbg(l, r);
  if (l == -1) return "";
  
  assert(l <= r);
  assert(l < s.size());
  assert(l>=0);
  return s.substr(l, r - l + 1);
}
};