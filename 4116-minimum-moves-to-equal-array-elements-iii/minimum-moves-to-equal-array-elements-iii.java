class Solution {
    public int minMoves(int[] nums) {
        int max_el = 0;
        for(int i = 0; i < nums.length;i++){
            max_el = Math.max(max_el, nums[i]);
        }
        int ans = 0;
        for(int i = 0 ;i < nums.length;i++){
            ans += max_el - nums[i];
        }
        return ans;
    }
}