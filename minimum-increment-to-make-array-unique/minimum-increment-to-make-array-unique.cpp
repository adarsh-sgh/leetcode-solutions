class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int make = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] > make){
                make = nums[i] + 1;
                continue;
            }else{
                ans += make - nums[i];
                make++;
            }
        }
        return ans;
    }
};