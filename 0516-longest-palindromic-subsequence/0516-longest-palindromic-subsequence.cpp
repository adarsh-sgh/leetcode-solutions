class Solution {
public:
    vector<vector<int>>dp;
    int n;
    string s;
    
    int lps(int i,int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // if(j-i <= 1)return s[i]==s[j]?j-i+1:0;
        if(s[i]==s[j]){
            dp[i][j] = 1 + (i!=j)+lps(i+1,j-1);
        }
        else dp[i][j] = max(lps(i+1,j),lps(i,j-1));
        return dp[i][j];
    }

    int longestPalindromeSubseq(string S) {
        s = S;
        n = s.size();
        
        dp.resize(n,vector<int>(n,-1));
        return lps(0,s.size()-1);
    }
};