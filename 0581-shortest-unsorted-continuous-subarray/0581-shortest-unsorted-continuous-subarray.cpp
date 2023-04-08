class Solution {
public:
#define dbg(...) 5;
   int findUnsortedSubarray(vector<int>& nums) {
  int n = nums.size();
  vector<bool>v(n, true);
  int li = 0;
  for (int i = 0;i < n;i++) {
    dbg(i);
    if (nums[i] >= nums[li]) li = i;
    else {
      v[i] = false;
      v[li] = false;
    }
  }
  dbg(v);

  int si = n - 1;
  for (int i = n - 1;i >= 0;i--) {
    if (nums[i] <= nums[si]) si = i;
    else {
      v[i] = false;
      v[si] = false;
    }
  }
  dbg(v);
  int fsi = -1, lsi = -1;
  for (int i = 0;i < n;i++) {
    if (!v[i]) {
      lsi = i;
      if (fsi == -1) fsi = i;
    }
  }
  if(fsi==-1) return 0;
  return lsi - fsi + 1;

}
};