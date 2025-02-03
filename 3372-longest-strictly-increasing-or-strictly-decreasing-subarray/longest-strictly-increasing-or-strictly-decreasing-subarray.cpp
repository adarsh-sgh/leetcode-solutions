class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int si = 1, sd = 1;
       int ans = 1;
       for(int i = 1;i< nums.size();i++){
        if(nums[i] > nums[i-1]){
            si++;
            ans = max(ans, si);
            sd = 1;
        }else if(nums[i] < nums[i-1]){
            sd++;
            ans = max(ans, sd);
            si = 1;
        }else{
            si = 1;sd = 1;
        }
       } 
       return ans;
    }
};