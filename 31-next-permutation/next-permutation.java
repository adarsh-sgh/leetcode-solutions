class Solution {
    public void nextPermutation(int[] nums) {
       int i = nums.length - 2;
       for(;i>=0;i--) if(nums[i] < nums[i+1]) break;
       if(i == -1){
        Arrays.sort(nums,0,nums.length);
        return;
       }
       int j = i + 1;
       int ja = j;
       for(;j<nums.length;j++){
        if(nums[j] < nums[ja] && nums[j] > nums[i]) ja = j;
       }
    nums[i] ^= nums[ja];
    nums[ja] ^= nums[i];
    nums[i] ^= nums[ja];
    Arrays.sort(nums,i+1,nums.length); 
    }
}