class Solution {
public:
#define dbg(...) 42;

vector<int>dir{ -1,0,1,0,-1 };
int slidingPuzzle(vector<vector<int>>& board) {
  string s;
  int i0;
  for (auto&& x : board) {
    for (auto&& y : x) {
      s += y + '0';
      if (s.back() == '0')i0 = s.size() - 1;
    }
  }
  dbg(s, i0);
  queue<pair<string, int>>q;
  q.push({ s,i0 });
  int dis = 0;
  set<string>vis;
  vis.insert(s);
  while (!q.empty()) {
    int n = q.size();
    while (n--) {
      auto [s, i] = q.front();
      q.pop();
      if (s == "123450")return dis;
      int x = i / 3, y = i % 3;
      for (int d = 0;d < 4;d++) {
        int xn = x + dir[d];
        int yn = y + dir[d + 1];
        if (xn < 0 || yn < 0 || xn > 1 || yn > 2) {
          continue;
        }
        int in = 3 * xn + yn;
        swap(s[i], s[in]);

        if (!vis.count(s)) {
          q.push({ s,in });
          vis.insert(s);
        }
        swap(s[i], s[in]);
      }
    }
    dis++;
  }
  return -1;

  // return minMoves(s, i0 / 3, i0 % 3);
}
};