class Solution {
public:
    int mod = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
       // dp[i][j] => word[*][i] tak use karke target[j] tak banane ke ways
       // dp[i][j] = dp[i - 1][j] + w[i][target[j]] * dp[i-1][j-1];
       int tn = target.size();
       int wc = words[0].size();
      vector<vector<int>>wv(wc,vector<int>(26));
      for(auto &w:words){
        for(int i = 0;i<wc;i++){
            wv[i][w[i] - 'a']++;
        }
      }
      vector<vector<long long>>dp(wc + 1,vector<long long>(tn + 1));
      dp[0][0] = wv[0][target[0] - 'a'];
      
      for(int i = 1;i<wc;i++){
        dp[i][0] = dp[i-1][0] + wv[i][target[0] - 'a'];
        for(int j = 1;j<tn;j++){
            dp[i][j] = dp[i-1][j] + wv[i][target[j] - 'a'] * dp[i-1][j-1];
            dp[i][j] %= mod;
        }
      }
    //   for(auto &x:dp){
    //     for(auto &y:x){
    //         cout<<y<<' ';
    //     }
    //     cout<<'\n';
    //   }
      return dp[wc-1][tn-1];
    }
};