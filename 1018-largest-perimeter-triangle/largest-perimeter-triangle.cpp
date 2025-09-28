class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int ans = 0, n = nums.size();
       for(int i = 2;i < n;i++){
        if(nums[i-1] + nums[i-2] <= nums[i])continue;
        ans = nums[i] + nums[i-1] + nums[i-2];
       }
       return ans;
    }
};