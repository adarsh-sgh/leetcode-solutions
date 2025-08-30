class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
        if(nums[i]==0)nums[i]=-1;
       } 
       int n = nums.size();
    //    vector<int>pf(n+1);
       int sum = 0;
       map<int,int>mp;
       mp[0] = -1;
       int ans = 0;
       for(int i = 0;i< n;i++){
            sum += nums[i];
            if(!mp.count(sum))mp[sum] = i;
            else ans = max(ans, i - mp[sum]);
       }
       return ans;
    }
    // 1 -1  1 1 -1 1 -1 -1
    // pf[i] = 5
    //
};