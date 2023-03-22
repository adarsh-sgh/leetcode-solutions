class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
  multiset<int> s(people.begin(), people.end());

  int cnt = 0;
  while (!s.empty()) {
    if (s.size() < 2) {
      cnt += s.size();
      return cnt;
    }
    // dbg(s);
    auto x = s.end();
    auto y = s.begin();
    x--;
    cnt++;
    if ((*x + *y) <= limit) {
      s.erase(y);
    }
    s.erase(x);

  }
  return cnt;
}
};