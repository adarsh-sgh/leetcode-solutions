class Solution {
public:
#define dbg(...) 42;
 

vector<int>pge, nge;
vector<int>dp;
int dm;
int mj(int i) {
  if (dp[i] != -1) return dp[i];
  int l = pge[i] + 1, r = nge[i] - 1;
  l = max(l, i - dm); r = min(r, i + dm);
  dp[i] = 0;
  for (int in = l;in <= r;in++) {
    if (in == i)continue;
    dp[i] = max(dp[i], mj(in) + 1);
  }
  return dp[i];
}

int maxJumps(vector<int>& arr, int d) {
  int n = arr.size();
  dm = d;
  pge = vector<int>(n, -1); nge = vector<int>(n, n);
  stack<int>md;
  dbg(pge);
  for (int i = 0;i < arr.size();i++) {
    while (md.size() && arr[md.top()] <= arr[i]) {
      nge[md.top()] = i;
      md.pop();
    }
    md.push(i);
  }
  md = stack<int>();
  for (int i = 0;i < n;i++) {
    while (md.size() && arr[md.top()] < arr[i]) {
      md.pop();
    }
    dbg(i, md.size());
    if (md.size()) {
      pge[i] = md.top();
    }
    md.push(i);
  }
  dbg(nge, pge);

  dp = vector<int>(n, -1);
  int ans = 0;
  for (int i = 0;i < n;i++) ans = max(ans, mj(i) + 1);
  dbg(dp);
  return ans;
}

};