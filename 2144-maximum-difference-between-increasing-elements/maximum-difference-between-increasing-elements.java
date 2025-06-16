class Solution {
    public int maximumDifference(int[] nums) {
        int ans = Integer.MIN_VALUE;
        int minTillNow =  nums[0];
        for(int i=1; i<nums.length; i++){
            ans = Math.max(ans, nums[i]-minTillNow);
            minTillNow = Math.min(minTillNow, nums[i]);
        }
        if(ans<=0){
            return -1;
        }
        return ans;
    }
}