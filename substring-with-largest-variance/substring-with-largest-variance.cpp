class Solution {
public:
#define dbg(...) 42;
 int largestVariance(string s) {
  int ans = 0;
  unordered_set<char>unique(s.begin(), s.end());
  dbg(unique);
  for (char a : unique)
    for (char b : unique) {
      int var = 0, first_b = 0, has_b = 0;
      for (auto c : s) {
        var += c == a;
        if (c == b) {
          has_b = true;
          if (first_b && var >= 0) {
            first_b = false;
          }
          else if (--var < 0) {
            var = -1;
            first_b = true;
          }
        }
        ans = max(ans, has_b ? var : 0);
        dbg(ans, has_b, first_b);
      }
    }

  return ans;
}
};