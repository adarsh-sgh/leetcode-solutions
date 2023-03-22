class Solution {
public:
    int integerBreak(int n) {
  int ans = 1;
  for (int i = 2;i <= 58;i++) {
    vector<int>v(i, n / i);
    int left = n % i;
    int index = 0;
    while (left--) {
      v[index]++;
      index++;
    }
    int prod = 1;
    for (auto&& x : v) {
      prod *= x;
    }
    ans = max(ans, prod);
  }

  return ans;
}
};