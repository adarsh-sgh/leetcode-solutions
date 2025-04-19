class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i = 0;i< nums.size();i++){
            // find the partner of nums[i] j, such that  j > i
            // nums[i] + nums[j] >= lower => 
            // nums[j] >= lower - nums[i]
            // nuums[j] <= upper - nums[i];
            auto it1 = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i])-nums.begin();
            auto it2 = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i])-nums.begin();
            ans+= (it2-it1);
        }
        return ans;
    }
};