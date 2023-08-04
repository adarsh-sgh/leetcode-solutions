class Solution {
public:
    set<string>wd;
string s;
vector<string>ans;
void bw(int index, string& su) {
  if (index == s.size()) {
    ans.push_back(su);
  }
  for (int i = index;i < s.size();i++) {
    if (wd.count(s.substr(index, i - index + 1))) {
      string sn = su + (su.size() ? " " : "") + s.substr(index, i - index + 1);
      bw(i + 1, sn);
    }
  }
}

vector<string> wordBreak(string S, vector<string>& wordDict) {
  string sx;
  wd = set<string>(wordDict.begin(), wordDict.end());
  s = S;
  bw(0, sx);
  return ans;
}
};