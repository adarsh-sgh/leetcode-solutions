class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int globalMax = nums[0], maxUpto = 0; 
       for(auto &x:nums){
        maxUpto = max(maxUpto + x, x);
        globalMax = max(maxUpto, globalMax);
       }
       return globalMax;
    }
};