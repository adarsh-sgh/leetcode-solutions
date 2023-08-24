class Solution {
public:
// copied 
int longestCycle(vector<int>& e) {
  int res = -1;
  vector<array<int, 2>> dp(e.size(), { -1, -1 });
  for (int i = 0; i < e.size(); ++i) {
    int distance = 0;
    for (int j = i; j != -1; j = e[j]) {
      auto [distance_i, from_i] = dp[j];
      if (distance_i != -1) {
        if (from_i == i)
          res = max(res, distance - distance_i);
        break;
      }
      dp[j] = { distance++, i };
    }
  }
  return res;
}

};