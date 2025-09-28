class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       // smallest length with sum >= target
       int i = 0, csum = 0, ans = nums.size() + 1;
       for(int j = 0;j < nums.size();j++){
        csum+= nums[j];
        while(csum >= target){
            ans = min(ans, j - i + 1);
            csum -= nums[i];
            i++;
        }
       }
       if(ans==nums.size() + 1)return 0;
       return ans;
    }
};