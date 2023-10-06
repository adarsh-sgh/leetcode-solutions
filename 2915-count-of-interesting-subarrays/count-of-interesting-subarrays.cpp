class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
  int n = nums.size();
  vector<int>p(n + 1);
  for (int i = 0; i < n; i++) {
    p[i + 1] = p[i] + (nums[i] % modulo == k);
  }
  map<int, int>mp;
  long long ans = 0;
//   dbg(p);
  for (int i = 0;i < n + 1;i++) {
    auto cur = p[i] % modulo;
    if (cur - k < 0) ans += mp[(-k + cur + modulo) % modulo];
    else ans += mp[(-k + cur) % modulo];
    mp[cur]++;
  }
  return ans;
}
};