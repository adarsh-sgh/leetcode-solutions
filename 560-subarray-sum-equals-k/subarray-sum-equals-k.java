class Solution {
    public int subarraySum(int[] nums, int k) {
     int n = nums.length;
    Map<Integer,Integer> mp = new HashMap<>();
    int sum = 0;
    int ans = 0;
    mp.put(0,1);
    for (int i = 0; i < n; i++) {
      sum+= nums[i];
      ans += mp.getOrDefault(sum - k, 0);
      mp.put(sum, mp.getOrDefault(sum, 0)+1);
    }
    return ans;
    }
}