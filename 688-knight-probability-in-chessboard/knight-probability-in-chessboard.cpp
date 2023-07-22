class Solution {
public:
    vector<int>dx = {1,1,-1,-1,2,2,-2,-2};
    vector<int>dy = {2,-2,2,-2,1,-1,1,-1};
    vector<vector<vector<double>>>dp;

   double knightProbability(int n, int k, int row, int column) {
     dp.resize(25,vector<vector<double>>(25,vector<double>(101,-1)));
     return kp(n,k,row,column);
   }
double kp(const int n, int k, int row, int column) {

  if (row < 0 || column < 0 || row >= n || column >= n) return 0;
  if (k == 0) return 1;
  if(dp[row][column][k]!=-1)return dp[row][column][k];

  double prob = 0;
  // long long cases = 0;
  for (int i = 0;i < 8;i++) {
    int rn = row + dx[i];
    int cn = column + dy[i];
    prob += kp(n, k - 1, rn, cn);
    // cases += kp(n,k-1,rn,cn);
    // dbg(prob);
  }
  prob /= 8;
  return dp[row][column][k] = prob;
  // dp[row][column][k] = cases;
}

};