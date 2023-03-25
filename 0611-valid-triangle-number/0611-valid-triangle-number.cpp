class Solution {
public:
#define dbg(...) 42;
   int countBetween(vector<int>& sorted, int lower, int upper, int index) {
  auto up = lower_bound(sorted.begin() + index, sorted.end(), upper) - sorted.begin() - 1;
  auto  lo = lower_bound(sorted.begin() + index, sorted.end(), lower) - sorted.begin() + 1;
  return up - lo + 1;
}
int triangleNumber(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int ans = 0;
  for (int i = 0;i < nums.size();i++) {
    for (int j = i + 1;j < nums.size();j++) {
      int a = nums[i], b = nums[j];
      int c = countBetween(nums, abs(a - b), a + b, j);
      // if (nums[i] > abs(a - b) && nums[i] < a + b) c--;
      // if (nums[j] > abs(a - b) && nums[j] < a + b) c--;
      dbg(nums[i], nums[j], c, i, j);
      ans += max(c,0);
    }
  }
  return max(ans,0);
}
};