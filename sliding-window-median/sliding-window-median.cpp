class Solution {
public:
    
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
  multiset<int>s1, s2;
  int n = nums.size();
  vector<double>ans;
  s1.insert(INT_MIN);
  s2.insert(INT_MAX);
  for (int i = 0;i < n;i++) {
    if (s1.size() == s2.size()) {
      // inr in s1 
      auto x = s2.begin();
      int a1 = min(*x, nums[i]);
      int a2 = max(*x, nums[i]);
      s2.erase(x);
      s1.insert(a1);s2.insert(a2);
    }
    else {
      // inr in s2 
      assert(s1.size() == s2.size() + 1);
      auto x = s1.rbegin();
      int a1 = min(*x, nums[i]);
      int a2 = max(*x, nums[i]);
      s1.erase(--x.base());
      s1.insert(a1);s2.insert(a2);
    }
    // j -> index to rem
    int rem = i - k;
    if (rem >= 0) {
      auto it1 = s1.find(nums[rem]);
      if (it1 != s1.end()) {
        s1.erase(it1);
        if (s1.size() < s2.size()) {
          auto x = s2.begin();
          s1.insert(*x);
          s2.erase(x);
        }
      }
      else {
        s2.erase(s2.find(nums[rem]));
        if (s2.size() == s1.size() - 2) {
          auto x = s1.rbegin();
          s2.insert(*x);
          s1.erase(--x.base());
        }
      }
    }
    int j = rem + 1;
    if (j >= 0) {
      double med;
      if (s1.size() != s2.size()) {
        med = *s1.rbegin();
      }
      else {
        med = (1.0 * (*s1.rbegin()) + (*s2.begin())) / 2.0;
      }
      ans.push_back(med);
    }
    assert(s1.size() - s2.size() == 1 || s1.size() == s2.size());
  }
  return ans;
}
};