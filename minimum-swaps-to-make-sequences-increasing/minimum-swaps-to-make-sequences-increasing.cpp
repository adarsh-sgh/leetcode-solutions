class Solution {
public:
int inf = 1e6;
int minSwap(vector<int>& nums1, vector<int>& nums2) {
  int n = nums1.size();
  vector<int>swp(n, n), nswp(n, n);
  swp[0] = 1;
  nswp[0] = 0;
  for (int i = 1;i < n;i++) {
    if (nums1[i] <= nums1[i - 1] || nums2[i] <= nums2[i - 1]) {
      //opposite operation 
      nswp[i] = swp[i - 1];
      swp[i] = nswp[i - 1] + 1;
    }
    else if (nums1[i] <= nums2[i - 1] || nums2[i] <= nums1[i - 1])  {
      swp[i] = 1 + swp[i - 1];
      nswp[i] = nswp[i - 1];
    }
    else {
      swp[i] = min(swp[i - 1], nswp[i - 1]) + 1;
      nswp[i] = min(swp[i - 1], nswp[i - 1]);
    }
  }
  return min(swp.back(), nswp.back());
}
};