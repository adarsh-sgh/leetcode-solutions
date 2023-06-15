class Solution {
public:
  
string rankTeams(vector<string>& votes) {
  vector<vector<int>>vt(26, vector<int>(27));
  for (int i = 0;i < 26;i++) {
    vt[i][26] = i;
  }
  for (auto&& v : votes) {
    for (int i = 0;i < v.size();i++) {
      char c = v[i];
      vt[c - 'A'][i]--;
    }
  }
  sort(vt.begin(), vt.end());
  string ans;
  for (auto&& x : vt) {
    ans.push_back(x[26] + 'A');
  }
  return ans.substr(0, votes[0].size());
}
};