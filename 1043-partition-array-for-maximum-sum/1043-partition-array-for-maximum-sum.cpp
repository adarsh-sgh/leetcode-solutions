class Solution {
public:
#define dbg(...) 42;
   vector<int>dp;
vector<int>v;
int n;
int ans = 0;
int k;
int msp(int index) {
  if (index >= n) return 0;
  if (dp[index] != -1) return dp[index];
  int mel = 0;
  int mx = mel;
  for (int i = 0;i < k;i++) {
    int in = index + i;
    if (in >= n) break;
    mel = max(mel, v[in]);
    mx = max(mx, mel * (i + 1) + msp(in + 1));
  }
  // dbg(index, mx);
  dp[index] = mx;
  return mx;
}
int maxSumAfterPartitioning(vector<int>& arr, int K) {
  k = K;
  n = arr.size();
  dp.resize(n, -1);
  v = arr;
  return msp(0);
}
};