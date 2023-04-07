class Solution {
public:
 
vector<vector<int>> combine(int n, int k) {
  unsigned long long bm = 1 << n;
  vector<vector<int>> ans;
  for (unsigned long long i = 0;i < bm;i++) {
    // printBinary(i);
    if (__builtin_popcount(i) != k) continue;
    vector<int>tmp;
    for (int j = 0;j < n;j++) {
      if (i & (1 << j)) {
        tmp.push_back(j + 1);
      }
    }
    ans.push_back(tmp);
  }
  return ans;
}
};