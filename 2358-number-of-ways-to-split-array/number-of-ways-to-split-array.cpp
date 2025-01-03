class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0ll); 
        long long csum = 0;
        int ans = 0;
        for(int i = 0;i<nums.size() - 1;i++){
            csum += nums[i];
            if(csum >= sum - csum)ans++;
        }
        return ans;
    }
};