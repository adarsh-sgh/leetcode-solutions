class Solution {
public:
#define dbg(...) 4;
   int findMinArrowShots(vector<vector<int>>& points) {
  set<pair<int, int>>s;
  for (auto&& x : points) {
    s.insert({ x[0],x[1] });
  }
  dbg(s);
  for (auto it = ++s.begin();it != s.end();) {
    auto pit = --it;
    it++;
    dbg(*it, *pit);
    if (it->first <= pit->second) {
      auto x = it->first;
      auto y = min(it->second, pit->second);
      it = s.erase(pit);
      it = s.erase(it);
      s.insert({ x,y });
      // it++;
    }
    else {
      it++;
    }
  }

  dbg(s);
  return s.size();
}
};