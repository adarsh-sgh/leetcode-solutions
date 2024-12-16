class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
       int j = 0;
       int n = nums.size();
       long long ans = 0;
       map<int,int>mp;
       for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            while(mp.rbegin()->first - mp.begin()->first > 2){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0) mp.erase(nums[j]);
                j++;
            } 
            ans += i - j + 1;
       } 
       return ans;
    }
};