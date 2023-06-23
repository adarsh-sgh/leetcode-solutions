class Solution {
public:
 int m, n, k;
bool good(int x) {
  int sum = 0;
  for (int i = 1;i <= m;i++) {
    int ni = x / i;
    ni = min(ni, n);
    sum += ni;
  }
  return sum >= k;
}

int findKthNumber(int M, int N, int K) {
  m = min(M, N);
  n = max(M, N);
  k = K;
  int l = 1,r = m*n;
  while(l<r){
    int mid = (l + r)/2;
    if(good(mid)){
      r = mid;
    }else{
      l = mid + 1;
    }
  }
  return l;
}
};