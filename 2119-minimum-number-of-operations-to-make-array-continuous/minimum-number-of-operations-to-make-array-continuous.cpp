class Solution {
public:
    int minOperations(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       long long sz = nums.size();
       auto it = unique(nums.begin(),nums.end());
       nums.erase(it,nums.end());
       int ans = INT_MAX;
       for(int i = 0;i<nums.size();i++){
            // cnt of nums in range nums[i] to nums[i] + nums[i] + nums.size() - 1;
            auto lb = lower_bound(nums.begin(),nums.end(),nums[i]);
            auto ub = upper_bound(nums.begin(),nums.end(),nums[i] + sz -1);
            ans = min(1ll *ans,sz - (ub-lb));
       }
       return ans;
    }
};