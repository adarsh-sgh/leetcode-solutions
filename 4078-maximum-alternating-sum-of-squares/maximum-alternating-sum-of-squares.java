class Solution {

    public long maxAlternatingSum(int[] nums) {
        for (int i = 0; i < nums.length; i++) nums[i] = Math.abs(nums[i]);
        Arrays.sort(nums);
        // Arrays.sort(nums, Integer.compare(Math.abs(a), Math.abs(b)));
        int i = 0, j = nums.length - 1;
        long sum = 0;
        while ( i <= j ){
            sum += nums[j] * nums[j];
            j--;
            if(i > j) break;
            sum -= nums[i] * nums[i];
            i++;
        }
        return sum;
    }
}