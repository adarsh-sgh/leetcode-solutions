class Solution {
public:
#define dbg(...) 42;
string vhash(vector<int>v) {
  assert(v.size() == 26);
  string res;
  for (int i = 0;i < 26;i++) {
    if (v[i]) res += (char)(i + 'a') + to_string(v[i]);
  }
  return res;
}
int inf = 1e9 + 5;
vector<string>stick;
// unordered_map<string, int>dp;
map<vector<int>,int>dp;
int minst(vector<int>target) {
  // string thash = vhash(target);
  auto &thash = target;
  dbg(thash, dp);
  if (dp.count(thash)) return dp[thash];
  dp[thash] = inf;
  int res = inf;
  for (auto&& s : stick) {
    auto tn = target;
    for (auto&& c : s) {
      if (tn[c - 'a'])tn[c - 'a']--;
    }
    res = min(res, minst(tn) + 1);
  }
  return dp[thash] = res;
}

int minStickers(vector<string>& stickers, string target) {
  stick = stickers;
  vector<int>t(26);
  for (auto&& c : target) {
    t[c - 'a']++;
  }
  // dp[""] = 0;
  dp[vector<int>(26)] = 0;
  int ans = minst(t);
  if(ans>=inf) return -1;
  return ans;
}

};