class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i = 0;i<4;i++){
            int sm = nums[i],
            lg = nums[i + nums.size() - 4];
            ans = min(ans,abs(lg - sm));
        }
        return ans;
    }
};