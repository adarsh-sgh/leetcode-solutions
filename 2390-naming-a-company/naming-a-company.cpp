class Solution {
public:
#define dbg(...) 42;
 long long distinctNames(vector<string>& ideas) {
  unordered_set<string>se(ideas.begin(), ideas.end());
  int n = ideas.size();
  vector<unordered_set<char>>m(n);
  
  vector<vector<int>>mp(128, vector<int>(128, 0));
  // map<char, map<char, int>>mp;
  // map<char, int>cnt;
  vector<int>cnt(128, 0);
  for (int i = 0;i < n;i++) { 
    cnt[ideas[i][0]]++;
    for (char c = 'a';c <= 'z';c++) {
      string conc = c + ideas[i].substr(1);
      dbg(conc);
      if (se.count(conc)) {
        mp[c][ideas[i][0]]++;
      }
      else {
        m[i].insert(c);
      }
    }
  }
  long long ans = 0;
  for (int i = 0;i < n;i++) {
    for (auto&& x : m[i]) {
      ans += cnt[x] - mp[ideas[i][0]][x];
    }
  }
  return ans;
}
};