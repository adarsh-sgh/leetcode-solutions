class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
  map<int, int>m;
  for (auto&& x : nums) {
    m[x]++;
  }
  int distinct = m.size();
  m.clear();
  int j = 0;
  int n = nums.size();
  int ans = 0;
  for (int i = 0;i < n;i++) {
    m[nums[i]]++;
    while (m.size() >= distinct) {
      m[nums[j]]--;
      if (!m[nums[j]])m.erase(nums[j]);
      j++;
    }
    if (j > 0 && m.size() == distinct - 1 && !m.count(nums[j - 1])) {
      ans += j;
    }
  }
  return ans;
}
};