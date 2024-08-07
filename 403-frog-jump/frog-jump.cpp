class Solution {
public:
#define dbg(...) 42;
    int n;
vector<map<int, int>> dp;
vector<int>v;
bool cc(int i, int j) {
  dbg(i, j, dp);
  if (i == v.size() - 1)return true;
  if (j < 0 || i >= v.size()) return false;
  if (dp[i].count(j))return dp[i][j];
  dp[i][j] = false;
  int x = v[i];
  //x+j-1,x+j,x+j+1
  for (int o = -1;o <= 1;o++) {
    auto lb = lower_bound(v.begin() + i, v.end(), x + j + o);
    if (lb != v.end() && *lb == x + j + o) {
      if (cc(lb - v.begin(), j + o))return dp[i][j] = true;
    }
  }
  return dp[i][j];
}
bool canCross(vector<int>& stones) {
  n = stones.size();
  v = stones;
  dp.resize(stones.size());
  if(stones[1] != 1)return false;
  dp[1][1] = true;
  for(int i = 1;i<stones.size();i++){
    for(auto &&[j,b]:dp[i]){
      for(int o = -1;o<=1;o++){
        int target = stones[i] + j + o;
        auto lb = lower_bound(stones.begin() + i, stones.end(),target);
        if(lb == stones.end()||*lb != target)continue;
        dp[lb - stones.begin()][j + o] = true;
      }
    }
  }
  return dp[n-1].size();
  // return cc(0, 0);
}
};