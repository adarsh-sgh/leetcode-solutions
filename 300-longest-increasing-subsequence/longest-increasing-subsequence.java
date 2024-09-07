class Solution {
    public int lengthOfLIS(int[] nums) {
            int n = nums.length;
    List<Integer> dp = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      int lb = Collections.binarySearch(dp, nums[i]);
      if(lb < 0) lb = -lb - 1;
      if(lb == dp.size()) dp.add(nums[i]);
      else dp.set(lb,nums[i]);
    }
    return dp.size();
    }
}