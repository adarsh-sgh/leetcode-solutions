class Solution {
public:
  bool maxdiff(int diff, vector<int>& v, int p) {
  for (int i = 0;i < v.size() - 1;i++) {
    if (v[i + 1] - v[i] <= diff) {
      p--;
      i++;
      if (p <= 0) return true;
    }
  }
  return false;
}
int minimizeMax(vector<int>& nums, int p) {
  int n = nums.size();
  if(p==0) return 0;
  sort(nums.begin(), nums.end());

  int l = 0, r = nums.back() - nums[0];
//   for (int i = l; i <= r;i++) {
//     dbg(i, maxdiff(i, nums, p));
//   }
  while (l < r) {
    int mid = (l + r) / 2;
    if (maxdiff(mid, nums, p)) {
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }
  return l;
}

};