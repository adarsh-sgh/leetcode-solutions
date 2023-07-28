class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>mp;
        int j = 0;
        int ans = 0;
        int sum  = 0;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
            sum += nums[i];
            while(mp[nums[i]]>1){
                mp[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};