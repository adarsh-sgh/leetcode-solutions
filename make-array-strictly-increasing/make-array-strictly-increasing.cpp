class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
  int n1 = arr1.size(), n2 = arr2.size();
  vector<map<int, int>>dp(n1 + 1);
  sort(arr2.begin(), arr2.end());
  dp[0][-1] = 0;
  for (int i = 1;i <= n1;i++) {
    for (auto&& [val, steps] : dp[i - 1]) {
      if (val < arr1[i - 1]) {
        if (!dp[i].count(arr1[i - 1])) dp[i][arr1[i - 1]] = steps;
        else dp[i][arr1[i - 1]] = min(dp[i][arr1[i - 1]], steps);
      }
      // else {
      auto ub = upper_bound(arr2.begin(), arr2.end(), val);
      if (ub == arr2.end())continue;
      if (!dp[i].count(*ub)) dp[i][*ub] = steps + 1;
      else dp[i][*ub] = min(dp[i][*ub], steps + 1);
      // }
    }
  }
//   for (auto&& x : dp) {
//     dbg(x);
//   }
  int ans = INT_MAX;
  if (dp.back().empty())return -1;
  for (auto&& [val, steps] : dp.back()) {
    ans = min(ans, steps);
  }
  return ans;
}
};