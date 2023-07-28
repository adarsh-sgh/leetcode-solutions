class Solution {
public:
   int inf = 1e5;
int mdr(vector<int>& t, vector<int>& b) {
  vector<int>dp(7);
  for (int i = 0;i < t.size();i++) {
    for (int j = 1;j < 7;j++) {
      if (t[i] != j) {
        if (b[i] != j)dp[j] = inf;
        else dp[j]++;
      }
    }
  }
  int ans = inf;
  for (int i = 1;i < 7;i++) ans = min(ans, dp[i]);
  return ans;
}

int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
  int ans = min(mdr(bottoms, tops), mdr(tops, bottoms));
  return ans == inf ? -1 : ans;
}
};