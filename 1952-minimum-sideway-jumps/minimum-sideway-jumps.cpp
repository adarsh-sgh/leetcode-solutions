class Solution {
public:
    int inf = 1e9 + 5;
int minSideJumps(vector<int>& obstacles) {
  int n = obstacles.size();
  vector<array<int, 3>>dp(n);
  dp[0] = { 1,0,1 };
  for (int i = 1;i < n;i++) {

    for (int j = 0;j < 3;j++) {
      dp[i][j] = dp[i - 1][j];
    }
    if (obstacles[i] != 0) {
      dp[i][obstacles[i] - 1] = inf;
    }
    for (int x = 0;x < 3;x++) {
      for (int y = 0;y < 3;y++) {
        if (obstacles[i] - 1 == x || x == y) continue;
        dp[i][x] = min(dp[i][x], dp[i][y] + 1);
      }
    }
  }
//   dbg(dp);
  return *min_element(dp.back().begin(), dp.back().end());
}
};