class Solution {
public:
    vector<int>p;
int inf = 1e5;
vector<vector<map<int,int>>>dp;
int mp(int i, int kleft, int holding) {
  if (i == p.size()||kleft <= 0) return 0;
  if(dp[i][kleft].count(holding))return dp[i][kleft][holding];
  // buy
  int &res = dp[i][kleft][holding];
   res = mp(i + 1, kleft, min(p[i], holding));
  // sell 
  if (holding < p[i])res = max(res, p[i] - holding + mp(i + 1, kleft - 1, inf));
  return res;
}
int maxProfit(int k, vector<int>& prices) {
  p = prices;
  dp.resize(prices.size(),vector<map<int,int>>(k+1));
  return mp(0, k, inf);
}
};