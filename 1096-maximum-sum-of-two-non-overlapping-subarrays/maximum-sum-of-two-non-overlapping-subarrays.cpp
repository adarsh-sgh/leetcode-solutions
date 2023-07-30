class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int fl, int sl) {
        if(fl > sl)swap(fl,sl);
        int n = nums.size();
        vector<int>pref(n+1);
        vector<int>rev(n);
        int s1 = 0, s2 = 0;
        for(int i = 0;i<n;i++){
            s1 += nums[i];
            s2 += nums[i];
            if(i - fl >= 0) s1 -= nums[i-fl];
            if(i-sl >= 0) s2 -= nums[i-sl];
            if(i)pref[i] = max(pref[i-1],s1);
            else pref[i] = s1;
            if(i)rev[i] = max(rev[i-1],s2);
            else rev[i] = s2;
        }
        s1 = 0;s2 =0;
        int ans = 0;
        for(int i = n-1;i>=0;i-- ){
            s1 += nums[i];
            s2 += nums[i];
            if(i + fl < nums.size()) s1 -= nums[i+fl];
            if(i + sl <nums.size()) s2 -= nums[i+sl];
            if(i) ans = max({ans,s2 + pref[i-1],s1 + rev[i-1]});
        }
        return ans;

    }
};