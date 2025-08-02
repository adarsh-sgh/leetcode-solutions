class Solution {
public:
    long long solve(string s){
        int n = s.size();
        vector<vector<long long>>dp(n+1, vector<long long>(3));
       
        for(int i = 0;i < n;i++){
           char c = s[i];
           dp[i+1][0] = dp[i][0] + (c == 'L');
           dp[i+1][1] = dp[i][1] + dp[i][0] * (c=='C');
           dp[i+1][2] = dp[i][2] + dp[i][1] * (c=='T');
        }
        return dp.back().back();
    }
    long long numOfSubsequences(string s) {
        // dp[i][0] -> "L" considering first i elements
        // dp[i][1] -> "LC" considering first i elements
        int n = s.size();
        vector<int>lp(n,0);
        vector<int>ts(n,0);
        int cCount = 0;
        lp[0] = s[0] == 'L';
        for(int i = 1;i < s.size();i++){
            lp[i] = lp[i-1] + (s[i] == 'L');
            cCount += s[i] == 'C';
        }
        ts.back() = s.back() == 'T';
        for(int i = n - 2;i >= 0;i--){
            ts[i] = ts[i+1] + (s[i] == 'T');
        };

        long long cGain = 0;
        for(int i = 1;i < n;i++){
            cGain = max(cGain, 1ll * lp[i] * ts[i]);
        }

        return max({cGain + solve(s), solve("L" + s), solve(s + "T")});
    }
};