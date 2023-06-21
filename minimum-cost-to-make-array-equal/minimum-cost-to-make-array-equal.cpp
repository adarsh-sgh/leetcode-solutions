class Solution {
public:
    #define ll long long
long long minCost(vector<int>& nums, vector<int>& cost) {
  int n = nums.size();
  vector<pair<int, int>>v;
  for (int i = 0;i < n;i++) {
    v.push_back({ nums[i], cost[i] });
  }
  sort(v.begin(), v.end());
  for (int i = 0;i < n;i++) {
    cost[i] = v[i].second;
    nums[i] = v[i].first;
  }
  vector<ll>nc(n + 1), c(n + 1);
  for (int i = 1;i <= n;i++) {
    nc[i] = 1ll * nums[i - 1] * cost[i - 1] + nc[i - 1];
    c[i] = c[i - 1] + cost[i - 1];
  }
  long long ans = __LONG_LONG_MAX__;
  for (int i = 0;i < n;i++) {
    long long curr = nums[i] * (-c.back() + 2 * c[i]) + nc.back() - 2 * nc[i];
    ans = min(ans, curr);
  }
  return ans;

}
};