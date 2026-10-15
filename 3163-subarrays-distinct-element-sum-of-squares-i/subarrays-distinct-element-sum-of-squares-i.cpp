class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n= nums.size();
        int ans = 0;
     for(int i = 0;i<n;i++){
         for(int j = i;j<n;j++){
            set<int>dist;
             for(int k = i;k<=j;k++){
                 if(!dist.count(nums[k]))
                 {
                    dist.insert(nums[k]);
                    // ans += nums[k];
                 }
             }
             ans += dist.size()* dist.size();
             // cout<<ans<<' ';
         }
     }   
        return ans;
    }
};