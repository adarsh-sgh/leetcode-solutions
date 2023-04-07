class Solution {
public:
#define dbg(...) 1;
const int mod = 1e9 + 7;
   int sumSubarrayMins(vector<int>& arr) {
  stack<int>md;
  int n = arr.size();
  vector<int> nge(n, n), pge(n, -1);
  dbg(arr);
  for (int i = 0;i < n;i++) {
    while (!md.empty() && arr[md.top()] > arr[i]) {
      int x = md.top();
      md.pop();
      nge[x] = i;
    }
    if (!md.empty()) {
      pge[i] = md.top();
    }
    md.push(i);
  }
  long long int ans = 0;
  for (int i = 0; i < n;i++) {
    // int l = nge[i] - pge[i] - 1;
    int l = i - pge[i];
    int r = nge[i] - i;
    // if (l == 1) ans += arr[i];
    // else
    ans = ans % mod;
    ans += ((1ll * arr[i] * l) % mod * r) % mod;
    dbg(l, i, ans);

  }
  return ans;
}
};
