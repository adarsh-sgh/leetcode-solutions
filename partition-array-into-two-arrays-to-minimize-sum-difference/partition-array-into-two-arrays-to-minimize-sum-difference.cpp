class Solution {
public:
#define dbg(...) 42;
 int minimumDifference(vector<int>& nums) {
  int ans = INT_MAX;
  int n = nums.size() / 2;
  vector<map<int, vector<int>>>v(2);
  for (int z = 0;z <= 1;z++) {
    for (int i = 0;i < (1 << n);i++) {
      int sum = 0;
      // if (__builtin_popcount(i) != n / 2) continue;
      int cnt = __builtin_popcount(i);
      for (int b = 0;b < n;b++) {
        if (i & (1 << b))sum += nums[b + n * z];
        // else sum -= nums[b + n * z];
      }
      dbg(sum);
      // printBinary(i);
      // ans = min(abs(sum), ans);
      v[z][cnt].push_back(sum);
    }
  }
  for (auto&& [ignr, x] : v[1]) {
    sort(x.begin(), x.end());
  }
  int sumAll = accumulate(nums.begin(), nums.end(), 0);
  dbg(v);
  for (auto&& [cnt, nums] : v[0]) {
    for (auto&& x : nums) {
      int cnt1 = n - cnt;
      dbg(cnt, cnt1);
      auto lb = lower_bound(v[1][cnt1].begin(), v[1][cnt1].end(), (sumAll) / 2 - x) - v[1][cnt1].begin();
      for (int off = -1; off <= 1;off++) {
        int in = lb + off;
        if (in < 0 || in >= v[1][cnt1].size())continue;
        ans = min(ans, abs(sumAll - 2 * (v[1][cnt1][in] + x)));
        dbg(v[1][cnt1][in], x, ans, cnt, cnt1);
      }
    }
  }
  dbg(v[0], v[1])
    return ans;
}
};