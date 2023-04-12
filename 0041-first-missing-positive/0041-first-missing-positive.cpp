class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        nums.assign(s.begin(),s.end());
        // sort(nums.begin(),nums.end());
        int i = lower_bound(nums.begin(),nums.end(),1) - nums.begin();
        if(i == nums.size()||nums[i] != 1) return 1;
        for(;i<nums.size()-1;i++){
            if(nums[i+1] != nums[i] +1) return nums[i]+1;
        }
        return nums.back() + 1;
    }
};