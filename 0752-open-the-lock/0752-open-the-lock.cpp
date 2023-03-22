class Solution {
public:
#define dbg(...) 42;
    int openLock(vector<string>& deadends, string target) {
  unordered_set<string>dd(deadends.begin(), deadends.end());

  queue<string>q;
  if (dd.count("0000")) return -1;
  q.push("0000");
  int level = 0;
  while (!q.empty()) {
    int n = q.size();
    while (n--) {
      auto x = q.front();
      q.pop();
      if (x == target) return level;
      for (int dir = -1;dir < 2;dir += 2) {
        for (int i = 0;i < 4;i++) {
          //inr ith digit
          int di = x[i] - '0';
          di += dir;
          di = (di + 10) % 10;
          string snew = x;
          snew[i] = di + '0';

          dbg(snew);
          if (!dd.count(snew))q.push(snew);
          dd.insert(snew);
        }
      }

    }
    level++;
  }
  return -1;

}
};