class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for(auto &&x:nums){
            x = x %p;
            sum+=x;
            sum%=p;
        }
        if(sum==0)return 0;
        int n = nums.size();
        vector<int>pref(n+1);
        map<int,int>mp;
        mp[0] = 0;
        int ans = n;
        for(int i = 1;i<pref.size();i++){
            pref[i] = pref[i-1] + nums[i-1];
            pref[i] %= p;
            if(mp.count(pref[i]-sum)){
                ans = min(ans,i - mp[pref[i]-sum]);
            }
            if(mp.count(pref[i]-sum+p)){
                ans = min(ans,i - mp[pref[i]-sum+p]);
            }
            mp[pref[i]] = i;
        }
        if(ans == n) return -1;
        return ans;
    }
};