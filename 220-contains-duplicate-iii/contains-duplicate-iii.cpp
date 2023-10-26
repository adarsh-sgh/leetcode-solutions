class Solution {
public:
#define dbg(...) 42;

   bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
  multiset<int>ms;
  for (int i = 0;i < nums.size();i++) {
    if (i - indexDiff - 1 >= 0)ms.erase(ms.find(nums[i - indexDiff - 1]));
    dbg(ms, nums[i], i);
    auto lb = ms.lower_bound(nums[i]);
    if (lb != ms.end() && *lb - nums[i] <= valueDiff) {
      dbg(*lb, nums[i], i);
      return true;
    }
    if (lb != ms.begin()) {
      --lb;
      if (abs(*lb - nums[i]) <= valueDiff) {
        dbg(*lb, nums[i], i);
        return true;
      }
    }
    ms.insert(nums[i]);
    dbg(ms, nums[i], i);
  }
  return false;
}
};