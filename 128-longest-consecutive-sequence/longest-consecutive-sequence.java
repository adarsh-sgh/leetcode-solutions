class Solution {
    public int longestConsecutive(int[] nums) {
    if(nums.length == 0) return 0;
    Set<Integer> se = new HashSet<>();
    Map<Integer, Integer> mp = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
      se.add(nums[i]);
    }
    // List<Boolean> visited = new ArrayList<>(Collections.nCopies(nums.length, false));
    int ans = 1;
    for (int i = 0; i < nums.length; i++) {
      if (mp.containsKey(nums[i]))
        continue;
      int curr = nums[i];
      while (se.contains(curr)) {
        if (mp.containsKey(curr)) {
          curr -= mp.get(curr);
          break;
        } else{
        mp.put(curr,0);
        curr--;
        }
      }
      mp.put(nums[i], nums[i] - curr);
      ans = Math.max(ans, mp.get(nums[i]));
    }
    // System.out.println(mp);
    return ans;
    
}
}