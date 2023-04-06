class Solution {
public:
#define dbg(...) 3;
vector<int> v;

  int ms(int n) {
  if (n <= 1) return 0;
  if (v[n] == -1) {
    return n;
  }
  int lfn = n / v[n];
  return ms(lfn) + v[n];
}
int minSteps(int n) {
  v.resize(1000 + 1, -1);
  for (int i = 2;i * i <= 1000;i++) {
    int x = i;
    for(;x<= 1000;x+=i) {
      if (v[x] == -1) v[x] = i;
    }

  }

  dbg(v);

  return ms(n);
}
};