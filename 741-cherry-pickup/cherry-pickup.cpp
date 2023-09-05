class Solution {
public:
    vector<vector<int>>g;
bool oob(int i, int j) {
  return i < 0 || j < 0 || i >= g.size() || j >= g.size() || g[i][j] == -1;
}
int inf = 1e9;
int dp[51][51][51][51];
int cp(int i1, int j1, int i2, int j2) {
  if (i1 == g.size() - 1 && j1 == g[0].size() - 1 && i1 == i2 && j1 == j2) return g[i1][j1];
  if (oob(i1, j1) || oob(i2, j2))return -inf;
  int& ans = dp[i1][j1][i2][j2];
  if (ans != -1) return ans;
  int curr = g[i1][j1];
  if (i1 != i2 || j1 != j2) {
    curr += g[i2][j2];
  }
  int mx = -inf;
  for (int d1 = 0;d1 < 2;d1++) {
    for (int d2 = 0;d2 < 2;d2++) {
      mx = max(mx, cp(i1 + d1, j1 + !d1, i2 + d2, j2 + !d2));
    }
  }
  return ans = curr + mx;
}

int cherryPickup(vector<vector<int>>& grid) {
  g = grid;
  memset(dp, -1, sizeof(dp));
  int ans =  cp(0, 0, 0, 0);
  return max(ans,0);
}
};