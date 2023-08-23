class Solution {
public:
#define dbg(...) 42;
    int longestEqualSubarray(vector<int>& nums, int k) {
//   unordered_map<int, deque<int>>mp;
  int n = nums.size();
  vector<deque<int>>mp(n+1);
  int ans = 0;
  for (int i = 0;i < nums.size();i++) {
    auto&& dq = mp[nums[i]];
    dq.push_back(i);
    while (dq.size()) {
      int ji = i - dq.front() + 1;
      if (ji - dq.size() <= k)break;
      dq.pop_front();
    }
    dbg(dq);
    ans = max(ans, (int)dq.size());
  }
  return ans;
}
};