class Solution {
public:
// see this first, sliding window kindof (substring questions normally sliding window ?)
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
    int longestAwesome(string s) {
        vector<int>dp(1<<10,s.size());
        int ans = 0;
        dp[0] = -1;
        int msk = 0;
        for(int i =0;i<s.size();i++){
            msk ^= 1<<(s[i]-'0');
            for(int j = 0;j<10;j++){
                int nm = msk ^ (1<<j);
                ans = max(ans,i-dp[nm]);
            }
            ans = max(ans,i-dp[msk]);
            dp[msk] = min(dp[msk],i);
        }
        return ans;
    }
};