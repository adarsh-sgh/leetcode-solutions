class Solution {
public:
  vector<int>v;
vector<vector<int>>dp;
int lfs(int i, int j) {
  // assert(i<j);
  if(i>=j) return 2;
  if (dp[i][j] != -1)return dp[i][j];
  int ui = lower_bound(v.begin(), v.end(), v[j] - v[i]) - v.begin();
  if (ui!=v.size() && v[ui]== v[j] - v[i] && ui  < i) {
    return dp[i][j] = lfs(ui, i) + 1;
  }
  return 2;
}
int lenLongestFibSubseq(vector<int>& arr) {
  v = arr;
  int n = v.size();
  dp.resize(n, vector<int>(n, -1));
  int ans = 2;
  for (int i = 0;i < n;i++) {
    for (int j = i + 1;j < n;j++) {
      ans = max(ans, lfs(i, j));
    }
  }
  if (ans == 2)return 0;
  return ans;
}
};