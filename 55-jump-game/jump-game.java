class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int range = 0;
       for(int i = 0;i<n;i++){
        if(range < i) return false;
        range = Math.max(range, i + nums[i]);
       }
       return range >= n-1;
    }
}