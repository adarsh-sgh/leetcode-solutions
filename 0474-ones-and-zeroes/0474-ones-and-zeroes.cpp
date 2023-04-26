class Solution {
public:
vector<int>ones;
vector<int>zeroes;
vector<vector<vector<int>>>dp;
int fmf(int m, int n, int i) {
  if (i == -1) return -1e9;
  if (m < 0 || n < 0) return 0;
  if (zeroes[i] > m || ones[i] > n) return 0;
  if (dp[m][n][i] != -1) return dp[m][n][i];
  int ans = 0;

ans = max(ans, fmf(m - zeroes[i], n - ones[i], i-1));

   dp[m][n][i] = max(fmf(m,n,i-1),1 + ans);
   return dp[m][n][i];
}

int findMaxForm(vector<string>& strs, int m, int n) {
  int N = strs.size();
  ones.resize(N);
  zeroes.resize(N);

  dp.resize(N+1, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));
  for (int i = 0;i < N;i++) {
    vector<int>cnt(2);
    for (auto&& c : strs[i]) cnt[c - '0']++;
    ones[i] = cnt[1];
    zeroes[i] = cnt[0];
  }

    if(ones[0]<=n && zeroes[0]<=m)
    dp[0][ones[0]][zeroes[0]] = 1;
    // 2,10,1
    // 0 0 2

    for(int i=1;i<N;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=m;k++){
                // caluclate dp[i][j][k]
                int op1 = dp[i-1][j][k];
                int op2 = -1e9;
                if(j-ones[i]>=0 && k-zeroes[i]>=0)
                op2 = 1+dp[i-1][j-ones[i]][k-zeroes[i]];
                dp[i][j][k] = max(op1,op2);
            }
        }
    }

    
   int ans = 0;
   for(int i=0;i<=n;i++){
       for(int j=0;j<=m;j++){
           ans = max(ans,dp[N-1][i][j]);
       }
   }
    
   return ans;
}
};