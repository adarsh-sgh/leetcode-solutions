class Solution {
public:
    int mod = 1e9 + 7;
  long long lm;
bool good(const int n, const int a, const int b, long long x) {
  long long cnt = x / a + x / b ;
  if(cnt<n)return false;
  cnt -= x / lm;
  return cnt >= n;

}
int nthMagicalNumber(int n, int a, int b) {
  if(a==b) return 1ll * n * a % mod;
  long long l = 0, r = 1e14;
  lm = lcm(a,b);
  while (l < r) {
    long long mid = l + (r - l) / 2;
    if (good(n, a, b, mid)) {
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }
  return l % mod;
}
};