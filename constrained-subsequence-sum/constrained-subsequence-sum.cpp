class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
  //md
  deque<pair<int, int>>dq;
  int ans = INT_MIN;
  for (int i = 0;i < nums.size();i++) {
    while (dq.size() && dq.front().second < i - k)dq.pop_front();
    if (dq.size())nums[i] = max(nums[i], nums[i] + dq.front().first);
    ans = max(ans, nums[i]);
    while (dq.size() && dq.back().first < nums[i])dq.pop_back();
    dq.push_back({ nums[i],i });
  }
  return ans;
}

};