class Solution {
public:
    int distinctSubseqII(string s) {
       int n = s.size();
       vector<long long>dp(n+1);
       dp[0] = 1;
       int mod = 1e9 + 7;
       int ans = 0;
       for(int i = 1;i<=n;i++){
            for(int j = i-1;j>=0;j--){
               dp[i] += dp[j]; 
               dp[i] %= mod;
               if(j == 0 || s[j-1] == s[i-1])break;
            } 
            ans += dp[i];
            ans %= mod;
       } 
       return ans;


    }
};