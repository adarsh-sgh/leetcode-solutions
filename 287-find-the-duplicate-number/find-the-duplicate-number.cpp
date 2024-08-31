class Solution {
public:
// see sept. 2022 submission for explanation
    int findDuplicate(vector<int>& nums) {
      int slow = 0, fast = 0;
      do{
        slow = nums[slow];
        fast = nums[nums[fast]];
      }while(slow != fast);
      slow = 0;
      while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
      }
      return slow;
    }
};