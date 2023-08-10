class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n+1);
        for(int i = 1;i<=n;i++){
            pref[i] = pref[i-1] + nums[i-1];
        }
        
        int sum = 0;
        vector<int>ans(n);
        for(int i = nums.size()-1;i>=0;i--){
            ans[i] = sum - pref[i] + (i  - (n-i-1))*nums[i];
            sum += nums[i];
        }
        return ans;
    }
};