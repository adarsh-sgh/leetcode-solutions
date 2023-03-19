class Solution {
public:

    vector<int>v;
    int n;

    int minOperations(vector<int>& nums, int x) 
        {
  n = nums.size();
  v.resize(n + 1);
  unordered_map<int, int>m;
  m[0] = 0;
  for (int i = 1;i <= n;i++) {
    v[i] = v[i - 1] + nums[i - 1];
    m[v[i]] = i;
  }
  int ts = v.back() - x;
  // make target sum of longest length
  if(ts < 0) return -1;
  int longestL = -1;
  for (int i = 1; i <= n; i++) {
    if (m.count(v[i] - ts)) {
      longestL = max(longestL, i - m[v[i] - ts] + 1);
    }
  }
//   dbg(v, longestL, ts);
  // cout << longestL << " longestL " << ts << endl;
  if (longestL == -1) return -1;
  return v.size() - longestL;
}
    
};