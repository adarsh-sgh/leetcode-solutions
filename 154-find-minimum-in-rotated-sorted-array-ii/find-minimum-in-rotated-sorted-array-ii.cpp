class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            int m = (l + r)/2;
            if(nums[l] < nums[r])return nums[l];
            else if(nums[l] > nums[r]){
                if(nums[m] >= nums[l]){
                    l = m + 1;
                }else{
                    r = m;
                }
            }else{
                r--;
            }
        }
        return nums[l];
    }
};