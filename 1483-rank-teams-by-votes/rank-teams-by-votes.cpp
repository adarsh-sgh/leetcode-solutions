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
  for (int i = 0;i<votes[0].size();i++) {
    ans.push_back(vt[i][26] + 'A');
  }
  return ans;
}
};