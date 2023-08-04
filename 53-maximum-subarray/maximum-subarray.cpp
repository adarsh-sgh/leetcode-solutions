class Solution {
public:
    int inf = 1e6;
    int maxSubArray(vector<int>& nums) {
        int maxUpto = -inf, mx = -inf;
        for(int i = 0;i<nums.size();i++){
            maxUpto = max(nums[i],nums[i] + maxUpto);
            mx = max(mx,maxUpto);
        }
        return mx;
    }
};