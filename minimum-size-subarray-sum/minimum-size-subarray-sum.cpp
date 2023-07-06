class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans =  INT_MAX;
        int i = 0;
        for(int j = 0;j<n;j++ ){
            sum += nums[j];
            while(sum >= target){ 
                ans = min(ans, j - i +1);
                sum -= nums[i];
                i++;
                }
        }
        return ans==INT_MAX?0:ans;
    }
};