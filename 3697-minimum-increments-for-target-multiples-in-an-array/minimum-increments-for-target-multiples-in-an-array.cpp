class Solution {
public:
  #define dbg(...) 42;
  long long cst(int sm,long long num, vector<int>&target){
  if(sm == 0) return 0;
  long long l = 1;
  for(int i = 0;i< target.size();i++){
      if(sm >> i & 1){
          l = lcm(target[i], l);
      }
      dbg(l);
  }
  dbg(l,num);
  long long ans;
  if(l >= num) ans =  l - num;
  else{
  // smallest multiple of l i.e. m such that l * m > num 
  // m > ceil ( num / l ) 
  long long m = (num + l - 1)/ l;
  dbg(l,m);
  ans = l * m - num;
  }
  if(ans > 1e9) return 1e9;
  return ans;  
}

int minimumIncrements(vector<int>& nums, vector<int>& target) {
         // hint: target.size() is very small,we can go 2^n for it :think:
         // dp[i][j] i elements se jth submask ko satisfy kar dene ke liye min inc.
         // ans = dp[n][1111(binary mein)]
         // for(every bm(16)){
           // for Every submask sm : sm1 | sm2 = bm
              // dp[i][bm] = cost(sm1) + dp[i-1][sm2]
              //dp[i][bm] = dp[i-1][]
      //    } 
      int n = nums.size();
      int tn = target.size();
      int inf = 1e9;
      vector<vector<long long>>dp(n+1,vector<long long>(16,inf));
      dp[0][0] = 0;
      // Line 84: i = 4,sm1 = 7,target = {5480, 9819, 6781}, nums[i-1] = 20,cs = -199358460
      // int test = cst( 7, 20, target);
      // dbg(test);
      // return 1;
      for(int i = 1;i<=n;i++){
          for(int sm1 = 0;sm1 < (1<<tn);sm1++){
              for(int sm2 = 0;sm2 < (1<<tn);sm2++){
                  // sm1 yahan banao sm2 peeche wale se lo
                  int bm = sm1 | sm2;
                  long long cs = cst(sm1, nums[i-1], target);
                  dbg(i,sm1, nums[i-1],cs);
                  if(dp[i-1][sm2] < inf)dp[i][bm] = min(dp[i][bm], dp[i-1][sm2] + cst(sm1, nums[i-1], target));
              }
          }
      }
    //   for(auto &x:dp){
    //     for(auto &y:x){
    //       if(y == inf) cout << "inf ";
    //       else cout << y << "   ";
    //     }
    //     cout << endl;
    //   }
      return dp[n][(1<<tn) - 1];
}

};