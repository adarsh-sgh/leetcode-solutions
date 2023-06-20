class Solution {
public:
    vector<int>jd;int d;
int inf = 1e6;
// considering tasks upto ji and days upto di
vector<vector<int>>dp;
int md(int ji, int di) {
  if (di == 0)return 0;
  if (ji + 1 < di || ji == -1) return 1e6;
  if (dp[ji][di] != -1)return dp[ji][di];
  int maxd = 0;
  int res = inf;
  if (di == 1) {
    for (int i = 0;i <= ji;i++) {
      maxd = max(maxd, jd[i]);
    }

    return dp[ji][di] = maxd;
  }
  for (int i = ji;i >= 0;i--) {
    if (i < di - 1)break;
    maxd = max(maxd, jd[i]);
    res = min(res, md(i - 1, di - 1) + maxd);
  }
  return dp[ji][di] = res;
}

int minDifficulty(vector<int>& jobDifficulty, int D) {
  jd = jobDifficulty;
  d = D;
  if (jd.size() < d)return -1;
  dp.resize(jd.size(), vector<int>(d + 1, -1));
  return md(jd.size() - 1, d);
}
};