class Solution {
public:
    vector<vector<long long>>dp;
    long long MOD = 1e9 + 7;
    // people aware since <= t time
    long long d,f;
    long long aware(long long n,long long t){
        if(t <= 0) return 0;
        if(n==1) return 1;
        assert(n >= 1);
        if(dp[n][t] != -1) return dp[n][t];
        long long  ans =   aware(n-1,t-1) + aware(n-1,f-1) - aware(n-1,d-1) + MOD;
        ans = ans % MOD;
        assert(ans >= 0);
        if(ans < 0 ){
            // cout<<aware(n-1,f-1) <<" and " <<aware(n-1,d-1)<<" D,F "<<d<<' '<<f<<endl;
        }
        dp[n][t] = max(ans,0ll) ;
        return dp[n][t];
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        d = delay;
        f = forget;
        dp.resize(n+1,vector<long long>(n+1,-1));
        return aware(n,forget) % MOD;
    }
};