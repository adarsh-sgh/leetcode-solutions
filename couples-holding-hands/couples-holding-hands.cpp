class Solution {
public:
int pnr(int n) {
  return n ^ 1;
}
int minSwapsCouples(vector<int>& row) {
  int n = row.size();
  int ans = 0;
  vector<int>pos(n);
  for (int i = 0;i < n;i++) {
    pos[row[i]] = i;
  }
  auto goesto = [&](int i) {
    return pnr(pos[pnr(row[i])]);
  };
  for (int i = 0;i < n;) {
    int j = goesto(i);
    if (j != i) {
      swap(row[i], row[j]);
      swap(pos[row[i]], pos[row[j]]);
      ans++;
    }
    else {
      i++;
    }
  }
  return ans;
}
};