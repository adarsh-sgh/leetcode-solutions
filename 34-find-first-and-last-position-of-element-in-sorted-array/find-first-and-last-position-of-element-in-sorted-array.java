class Solution {
    public int[] searchRange(int[] nums, int target) {
    int n = nums.length;
    if(n == 0) return new int[]{-1,-1};
    int l = 0, r = n - 1;
    List<Integer> ans = new ArrayList<>();
    while (l < r) {
      int m = (l + r) >> 1;
      // f f f t t t find no. nums[i] >= target
      if (nums[m] >= target) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    if (nums[l]== target)
      ans.add(l);
    else return new int[]{-1,-1};
    l = 0; r = n-1;
    while(l < r){
      int m = (l + r + 1) >> 1;
      if(nums[m] <= target){
        l = m;
      }else{
        r = m - 1;
      }
    }
    ans.add(l);
    return ans.stream().mapToInt(x -> x).toArray();
    }
}