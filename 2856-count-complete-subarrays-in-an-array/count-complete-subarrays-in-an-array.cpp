class Solution {
public:
        int countCompleteSubarrays(vector<int>& nums) {
  map<int, int>m;
  for (auto&& x : nums) {
    m[x]++;
  }
  int distinct = m.size();
  m.clear();
  int i = 0;
  int n = nums.size();
  int ans = 0;

  for (int j = 0;j < n;j++) {
    m[nums[j]]++;
    while (m.size() >= distinct) {
      m[nums[i]]--;
      if (!m[nums[i]])m.erase(nums[i]);
      ans += nums.size() - j;
      i++;
    }
  }
  return ans;
}

};