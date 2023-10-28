class Solution {
public:
    int countVowelPermutation(int n) {
        // int dp[n+1][5];
        vector<vector<int>>dp(n+1,vector<int>(5));
        int mod = 1e9 + 7;
        dp[1] = vector<int>(5,1);

        vector<vector<int>>next = {
            {1},
            {0,2},
            {0,1,3,4},
            {2,4},
            {0}
        };
        for(int i = 1;i<n;i++){
            for(int j = 0;j<5;j++){
                for(auto n:next[j]){
                    dp[i+1][n]+=dp[i][j];
                    dp[i+1][n] %= mod;
                }
            }
        }
        int res = 0;
        for(int i = 0;i<5;i++){
            res += dp[n][i];
            res %= mod;
        }
        return res;
    }
};