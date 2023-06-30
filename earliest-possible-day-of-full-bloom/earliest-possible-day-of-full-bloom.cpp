class Solution {
public:
   int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
  int n = plantTime.size();
  vector<vector<int>>v(n);
  for (int i = 0;i < n;i++) {
    v[i] = { growTime[i],plantTime[i] };
  }
  sort(v.begin(), v.end());
  int ans = 0, pt = 0;
  for (int i = n - 1;i >= 0;i--) {
    ans = max(ans, v[i][1] + v[i][0] + pt);
    pt += v[i][1];
  }
  return ans;
}
};