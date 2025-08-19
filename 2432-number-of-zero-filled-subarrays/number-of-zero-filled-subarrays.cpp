class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       // let dp[i] => longest subarray ending at i with all 0 
       // ans = sum(dp);
       long long ans = 0;
       int curr = 0;
       for(auto &x:nums){
        if(x == 0)curr++;
        else curr = 0;
        ans += curr;
       } 
       return ans;
    }
};