class Solution {
    public int longestConsecutive(int[] nums) {
        // smallest no. is leader of group ignore rest
        Set<Integer> se = new HashSet<>();
        for(int i = 0;i<nums.length;i++){
            se.add(nums[i]);
        }
        int ans = 0;
        for(int i = 0;i<nums.length;i++){
            if(se.contains(nums[i]-1))continue;
            int curr = nums[i];
            while(se.contains(curr)){
                curr++;
            }
            ans = Math.max(ans, curr - nums[i]);
        }
        return ans;
    }
}