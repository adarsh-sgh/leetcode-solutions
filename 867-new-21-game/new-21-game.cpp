class Solution {
public:
// dp[i] = (dp[i-1] + dp[i-2]... dp[i-mp])*1/mp;
// ans = sum(dp[k]...dp[n]);
// .... i 
    double new21Game(int n, int k, int mp) {
       // k to n 
       if(n - k >= mp) return 1;
       if( k == 0 ) return 1;
       vector<double> dp(n+1);
        dp[0] = 1.0;
       double smp = 1.00;
       double ans = 0;
       for(int i = 1;i < n+1;i++){
        if(i - mp - 1 >= 0)smp -= dp[i - mp - 1];
        dp[i] = smp * 1.0 / mp;
        if(i >= k) ans += dp[i];
        if(i < k)smp+= dp[i];
        // cout << i<< ' ' <<smp<< ' '<<dp[i]<<endl;
       }
       return ans;
       ans = 0;
       for(int i = k - 1;i >= max(0,k - mp); i--){
            // ways to jump from here to [k...n]
            // jump by k - i+ 
            // jump by n - i-
            int l = k - i;
            int r = n - i;
            r = min(r, mp);
            if(l > r) continue;
            ans += (r-l+1)*1.0/mp;
       }
       return ans;
    }
};