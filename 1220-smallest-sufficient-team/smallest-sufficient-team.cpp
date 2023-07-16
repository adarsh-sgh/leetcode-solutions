class Solution {
public:
   map<string, int>m;
int n;
vector<unsigned int>p;
vector< unordered_map<unsigned int, vector<int>>>dp;
vector<int> sst(int index, unsigned int bmt) {
  if (index >= p.size()) {
    if (bmt == 0) return {};
    return {-1};
  }
  if (dp[index].count(bmt))return dp[index][bmt];
  auto c1 = sst(index + 1, bmt);
  if(!p[index])return dp[index][bmt] = c1;
  auto c2 = sst(index + 1, (~p[index]) & bmt);
  c2.push_back(index);
  if (((c1.size() &&c1[0]== -1) ||c1.size() > c2.size()))return dp[index][bmt] = c2;
  return dp[index][bmt] = c1;
}
vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
  n = req_skills.size();
  for (int i = 0;i < req_skills.size();i++) {
    m[req_skills[i]] = i;
  }
  for (auto&& x : people) {
    unsigned int curr = 0;
    for (auto&& y : x) {
      curr |= (1 << m[y]);
    }
    p.push_back(curr);
  }
  dp.resize(p.size());
  unsigned int allskills = (1 << n) - 1;

  return sst(0, allskills);
}

};