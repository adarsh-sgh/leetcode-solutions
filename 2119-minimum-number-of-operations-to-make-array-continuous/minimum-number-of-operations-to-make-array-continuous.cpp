class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int N = nums.size();
        auto ip = unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),ip));
        long  ops = 1e6;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            //if the seq starts at nums[i]
            // nums[i], nums[i] + n - 1
            auto x = lower_bound(nums.begin(),nums.end(),nums[i]) - 1;
            auto y = upper_bound(nums.begin(),nums.end(),nums[i] + N - 1) - 1;
            ops = min(ops,N - (y - x));
        }
        return ops;
    }
};