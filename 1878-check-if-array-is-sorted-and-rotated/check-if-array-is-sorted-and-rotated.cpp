class Solution {
public:
    bool check(vector<int>& nums) {
       bool ex = false;
       for(int i = 1;i< nums.size();i++){
        if(nums[i] < nums[i - 1]){
            if(ex) return false;
            ex = true;
        }
       } 
       return !ex  || nums[0] >= nums.back();
    }
};