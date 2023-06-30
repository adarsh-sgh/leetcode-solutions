class Solution {
public:
#define dbg(...) 42;
   vector<int>dp;
int winningState(int n) {
  if (n < 2) return n;
  if (dp[n] != -1) return dp[n];
  for (int a = 1;a * a <= n;a++) {
    int bb = n - a * a;
    if (!winningState(bb))return dp[n] = true;
  }
  return dp[n] = false;
}
bool winnerSquareGame(int n) {
  dp.resize(n + 1, -1);
  winningState(n);
  dbg(dp);
  return winningState(n);
}
};