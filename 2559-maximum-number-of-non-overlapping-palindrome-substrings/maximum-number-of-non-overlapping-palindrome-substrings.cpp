class Solution {
public:

    int maxPalindromes(string s, int k) {
        // select k, k+1 max 
        int n = s.size();
        vector<vector<int>>pal(n + 1, vector<int>(n + 1, 0));
        for(int i = n-1;i >=0; i--){
            pal[i][i] = 1;
            for(int j = i+1; j < n; j++){
                if(j== i+1) pal[i][j] = s[i] == s[j];
                else pal[i][j] = pal[i+1][j-1] && s[i] == s[j];
            }
        }
        // second dp
        // max palindrome taking subs [0...i]
        vector<int> dp(n + 1);
        for(int i = 1;i <= n;i++){
            dp[i] = dp[i-1];
            for(int j = 0;j<i;j++){
                dp[i] = max(dp[i], dp[j] + (pal[j][i-1] && (i-j >= k)));
            }
        }
        for(auto &x:dp){
            cout<<x<<' ';
        }
        return dp.back();
    }
    
};

// is palindrome marks each dp[i][j] saying if i to j is a palindrome
// dp[i] = dp[j] + 1 if j..i is palindrome 
