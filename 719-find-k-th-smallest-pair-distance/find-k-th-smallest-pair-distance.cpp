class Solution {
public:
   vector<int> v;int k;

// no of pairs with diff <= x
int leq(int x) {
  int res = 0;
  for (int i = 0;i < v.size();i++) {
    auto ub = upper_bound(v.begin() + i, v.end(), v[i] + x) - v.begin() - 1;
    res += ub - i;
  }
  return res;
}

int smallestDistancePair(vector<int>& nums, int K) {
  sort(nums.begin(), nums.end());
  v = nums;
  k = K;
  int l = 0, r = *max_element(nums.begin(), nums.end());
//   for (int i = l;i <= r;i++) {
//     dbg(i, leq(i));
//   }
  while (l < r) {
    int m = (l + r) / 2;
    if (leq(m) >= k) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }
  return l;
}
};