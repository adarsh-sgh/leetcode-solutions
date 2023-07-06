class Solution {
public:
    vector<vector<int>>g;
// cnt of seq with sum <= sum
vector<unordered_map<int,int>>dp;
int k;
int cnt(int sum, int row) {
  if (sum < 0) return 0;
  if (row == g.size())return 1;
  if(dp[row].count(sum))return dp[row][sum];
  int &res = dp[row][sum];
  for (int i = 0;i < g[row].size();i++) {
    if(res > k) return res;
    res += cnt(sum - g[row][i], row + 1);
  }
  return res;
}

bool good(int sum, int k) {
  int c = cnt(sum, 0);
  return c >= k;
}

int kthSmallest(vector<vector<int>>& mat, int K) {
  g = mat;
  k = K;
  dp.resize(g.size());
  int l = 0, r = 2e5;
  while (l < r) {
    int sum = (l + r) / 2;
    if (good(sum, k)) {
      r = sum;
    }
    else {
      l = sum + 1;
    }
  }
  return l;
}

};