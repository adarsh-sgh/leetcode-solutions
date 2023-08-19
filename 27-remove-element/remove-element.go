func removeElement(nums []int, val int) int {
     r := len(nums) - 1;
     for l:= 0;l<=r; {
         if nums[l] == val {
             nums[l] = nums[r];
             r--;
         }else{
             l++;
         }
     }
     return r + 1;
}