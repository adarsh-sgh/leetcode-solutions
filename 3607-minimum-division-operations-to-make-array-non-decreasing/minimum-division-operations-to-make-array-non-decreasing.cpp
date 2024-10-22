class Solution {
public:
    vector<int>smf;
    int minOperations(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());
        smf.resize(n + 5,1e7);
        vector<int>p(n + 5, 1);
       for(int i = 2;i * i <= n;i++){
           if(!p[i])continue;
            for(int j = 2 * i;j<=n;j+=i){
                 smf[j] = min(smf[j],i);
                p[j] = 0;
            }
       } 
    //    cout<<smf[5];
       int ans = 0;
       for(int i = nums.size()-2;i>=0;i--){
         if(nums[i] <= nums[i+1])continue;
        if(smf[nums[i]] > nums[i+1]) return -1;
        ans++;
        nums[i] = smf[nums[i]];
       }
       return ans;
    }
};