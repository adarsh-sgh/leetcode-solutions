class Solution {
public:
    unordered_map<int,int>dp;

    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 1;
       for(auto &&x:arr){
           if(dp.count(x-difference)){
               dp[x] = max(dp[x],dp[x-difference] + 1);
               ans = max(ans,dp[x]);
           }else{
               dp[x] = 1;
           }
       } 
       return ans;
    }
};