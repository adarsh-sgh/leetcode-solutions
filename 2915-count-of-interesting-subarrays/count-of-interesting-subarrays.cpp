class Solution {
public:

    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int>ok(n);
        for(int i = 0;i< n;i++) ok[i] = (nums[i] % modulo) == k;
        vector<int>p(n+1);
        for(int i = 1;i<=n;i++){
            p[i] = (p[i-1] + ok[i - 1]) % modulo;
        }
        for(auto &x:p)cout<<x<<' ';
        // at py find px such that
        // py - px % m == k
        // (m + py % m  - px % m) % m = k
        // px  = py  - k  or m + py - k = px
        // py = (k + px) % m wale numbers
        map<int,int>mp;
        long long ans = 0;
        for(int i = 0;i< p.size();i++){
            ans += mp[(p[i] - k + modulo) % modulo];
            mp[p[i]]++;
        }
        return ans;
    }

};