class Solution {
public:
    #define dbg(...) 42;
    #define ll long long
vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
  int n = nums.size();
  vector<pair<ll, int>>lmax(n + 1), rmax(n + 1);
  vector<ll> pref(n + 1);
  ll sum = 0;
  for (int i = 0;i < n;i++) {
    sum += nums[i];
    int j = i - k + 1;
    if (j - 1 >= 0)sum -= nums[j - 1];
    if (j >= 0) {
      if (sum > lmax[i].first) {
        lmax[i + 1] = { sum,j };
      }
      else {
        lmax[i + 1] = lmax[i];
      }
    }
  }
  sum = 0;
  for (int i = n - 1;i >= 0;i--) {
    sum += nums[i];
    int j = i + k - 1;
    if (j + 1 < nums.size())sum -= nums[j + 1];
    if (j < nums.size()) {
      if (sum >= rmax[i + 1].first) {
        rmax[i] = { sum,i };
      }
      else {
        rmax[i] = rmax[i + 1];
      }
    }
  }
  for (int i = 1;i <= n;i++) {
    pref[i] = pref[i - 1] + nums[i - 1];
  }
  dbg(lmax, rmax, pref);
  vector<int> ans;
  int high = 0;
  for (int i = k;i < nums.size() - k;i++) {
    ll curr = pref[i + k] - pref[i] + lmax[i].first + rmax[i + k].first;
    dbg(i, curr);
    if (curr > high) {
      ans = { lmax[i].second,i,rmax[i + k].second };
      high = curr;
    }
  }
  return ans;
}
};