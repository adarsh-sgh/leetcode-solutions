class Solution {
public:
     int lcs(string &s1, string &s2){
        // ascii sum of retained chars
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2 + 1));
        for(int i = 0;i < n1;i++){
            for(int j = 0;j < n2;j++){
                if(s1[i] == s2[j]){
                    dp[i + 1][j + 1] = dp[i][j] + s1[i];
                }else{
                    dp[i+1][j + 1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp.back().back();
    }
    int minimumDeleteSum(string s1, string s2) {
     // lcs 
        int total = 0;
        for(auto &c:s1) total += c;
        for(auto &c:s2) total += c;
        return total - 2 * lcs(s1, s2);
    }
};