class Solution {
public:
    #define dbg(...) 42;
int minAbsDifference(vector<int>& nums, int goal) {
  set<long long>s1, s2;
  int n = nums.size();
  vector<int>nums2;
  for (int i = n - 1;i >= n / 2;i--) {
    nums2.push_back(nums.back());
    nums.pop_back();
  }

  for (int bm = 0;bm < (1 << nums.size());bm++) {
    int sum = 0;
    for (int i = 0;i < nums.size();i++) {
      if (bm & (1 << i)) {
        sum += nums[i];
      }
    }
    s1.insert(sum);
  }
  for (int bm = 0;bm < (1 << nums2.size());bm++) {
    long long sum = 0;
    for (int i = 0;i < nums2.size();i++) {
      if (bm & (1 << i)) {
        sum += nums2[i];
      }
    }
    s2.insert(sum);
  }
  dbg(nums, nums2, s1, s2);
  long long ans = INT_MAX;
  for (auto&& x : s1) {
    auto it = s2.lower_bound(goal - x);
    if (it == s2.end()) it--;
    ans = min(ans, abs(*it + x - goal));
    if (it == s2.begin())continue;
    it--;
    ans = min(ans, abs(x + *it - goal));
  }
  return ans;
}
};