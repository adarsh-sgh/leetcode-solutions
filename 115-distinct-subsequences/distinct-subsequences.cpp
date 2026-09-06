class Solution {
public:
    int numDistinct(string s, string t) {
       // tc n * m is okay
       // can it be lcs ? 
       // dp[i][j] s[i] tak chars use karke t[j] banane ke ways
      int n = s.size(), m = t.size();
      vector<vector<unsigned long long>>dp(n+1, vector<unsigned long long>(m+1));
      // dp[*][0] = 1
      dp[0][0] = 1;  
      for(int i = 0;i < n;i++){
        dp[i][0] = 1;
        for(int j = 0;j < m;j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
            }else{
                dp[i+1][j+1] = dp[i][j+1];
            }
        }
      }
      return dp.back().back();
    }
};