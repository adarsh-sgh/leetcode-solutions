class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
       for(int i = 0;i < nums.size();i++){
        int mx = nums[0];
        for(int k = 0;k <=i;k++){
            mx = max(mx, nums[k]);
        }
        int mn = nums[i];
        for(int k = i;k < nums.size();k++){
            mn = min(mn,nums[k]);
        }
        if(mx - mn <= k){
            return i;
        }
       }
       return -1;
    }
};