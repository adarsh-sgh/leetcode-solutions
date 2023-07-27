class Solution {
public:
vector<int>dp;

    int ca(int n, int bm) {
  // cout << n << endl;
  // printBinary(bm);
  // cout << endl;
  if (n == 1) return 1;
  int &ans = dp[bm];
  if(ans!=-1) return ans;
  ans = 0;
  for (int i = 14;i >= 0;i--) {
    if ((bm & (1 << i)) && ((i + 1) % n == 0 || n % (i + 1) == 0)) {
      int bmn = bm & ~(1 << i);
      ans += ca(n - 1, bmn);
    }
  }
  return ans;
}

int countArrangement(int n) {
  dp.resize(1<<16,-1);
  return ca(n, (1 << n) - 1);
}
};