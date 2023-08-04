class Solution {
public:
    set<string>ans;
string s;
void rip(int i, int o, string& sup) {
  if (i == s.size()) {
    if (o == 0) {
      ans.insert(sup);
    }
    return;
  }
  if (o < 0)return;
  int d = 0;
  if (s[i] == ')')d = -1;
  else if (s[i] == '(') d = 1;
  sup += s[i];
  rip(i + 1, o + d, sup);
  sup.pop_back();
  if (d) rip(i + 1, o, sup);
}
vector<string> removeInvalidParentheses(string S) {
  s = S;
  string sup;
  rip(0, 0, sup);
  int mxsz = 0;
  vector<string>af;
  for (auto&& x : ans) {
    mxsz = max(mxsz, (int)x.size());
  }
  for (auto&& x : ans) {
    if (x.size() == mxsz)af.push_back(x);
  }
  return af;
}
};