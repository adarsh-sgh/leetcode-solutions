class Solution {
public:
    vector<int>sv;
vector<int>dp;
int maxLead(int i) {
  if (i >= sv.size()) return 0;
  vector<int>c;
  int res = 0;
  if(dp[i]!=-1) return dp[i];
  dp[i] = -1e6;
  int &ans = dp[i];
  for (int in = 0;in < 3;in++) {
    if(i+in>=sv.size())break;
    res += sv[i + in];
    ans = max(ans, res - maxLead(i + in + 1));
  }
  return ans;
}

string stoneGameIII(vector<int>& stoneValue) {
  sv = stoneValue;
  int n = sv.size();
  dp.resize(n,-1);
  int ml = maxLead(0);
  if(ml==0) return "Tie";
  if(ml>0) return "Alice";
  return "Bob";
}
};