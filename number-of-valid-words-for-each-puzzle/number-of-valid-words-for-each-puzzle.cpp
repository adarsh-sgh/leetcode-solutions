class Solution {
public:
  
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
  // vector<int>v;
  unordered_map<int, int>m;
  for (auto&& w : words) {
    int msk = 0;
    for (auto&& c : w) {
      msk |= (1 << (c - 'a'));
    }
    m[msk]++;
    // v.push_back(msk);
  }
  vector<int>ans;
  for (auto&& p : puzzles) {
    ans.push_back(0);
    int pmsk = 0;
    for (auto&& c : p) {
      pmsk |= (1 << (c - 'a'));
    }
    for (int s = pmsk; s; s = (s - 1) & pmsk) {
      if (!(s & (1 << (p[0] - 'a'))) || !m.count(s))continue;
      ans.back() += m[s];
    }
    // for (auto&& wm : v) {
    //   if (!(wm & (1 << (p[0] - 'a'))))continue;
    //   if ((wm & pmsk) != wm) continue;
    //   ans.back()++;
    // }
  }
  return ans;
}
};