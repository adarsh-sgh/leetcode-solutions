class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(),0ll);
        int r = sum % p;
        // smallest subarray with sum = r or p + r, r + 2p
        // %p 
        // [3,1,2,4] = sum = 10
        // 4
        int n = nums.size();
        vector<int>pre(n+1);
          map<int,int>mp;
          mp[0] = 0;
        for(int i = 1;i<=n;i++){
            pre[i] = pre[i-1] + nums[i-1];
            pre[i] %= p;
        }
        if(r==0) return 0;
        
        int ans = n + 1;
        // r = 7
        for(int i = 1;i<=n;i++){
            // p[i], p[i] - r
            // cout<<pre[i]<<' ';
            int target = (pre[i] - r + p) % p;
            // if(i==n){
            //     cout<<endl;
            // //  cout<<target<<' '<<mp[target];   
            // }
            if(!mp.count(target)){
                mp[pre[i]] = i;
                continue;
            }
            int j = mp[target];
            ans = min(ans, i - j);
            mp[pre[i]] = i;
        }
        if(ans == n) return -1;

        // 6 3 5 2, p = 9
        // 0 6 9 14 16
        // 0, 6, 0, 5, 7
        return ans;
    }
};