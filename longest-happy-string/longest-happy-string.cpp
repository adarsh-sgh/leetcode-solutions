class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
  priority_queue <pair<int, char>>q;
  if (a) q.push({ a,'a' });
  if (b) q.push({ b,'b' });
  if (c) q.push({ c,'c' });
  string s = "";
  while (!q.empty()) {
    auto t = q.top();
    q.pop();
    int i = s.size() - 1;
    if (s.size() >= 2 && t.second == s[i] && t.second == s[i - 1]) {
      if (q.empty())return s;
      auto t2 = q.top();
      q.pop();
      q.push(t);
      t = t2;
    }
    t.first--;
    s += t.second;
    if (t.first) {
      q.push(t);
    }
  }
  return s;
}
};