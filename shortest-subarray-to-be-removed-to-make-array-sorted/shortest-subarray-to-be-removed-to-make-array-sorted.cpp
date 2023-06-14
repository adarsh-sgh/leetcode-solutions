class Solution {
public:
    vector<int>v;
int n;
int sortedUpto, sortedAfter;
int good(int len) {
  // we can remove i to j iff
  // i -1 tak sorted hai , j+1 ke aage sorted hai and i-1th j+1th se kam ya barabar hai 
  // j = i + len -1
  if (len >= n) return true;
  for (int i = 0;i + len - 1 < n;i++) {
    if (sortedUpto >= i - 1 && sortedAfter <= i + len && (i + len >= n || i-1<0||v[i-1] <= v[i + len])) {
      return true;
    }
  }
  return false;
}
int findLengthOfShortestSubarray(vector<int>& arr) {
  v = arr;
  n = arr.size();
  sortedUpto = 0;sortedAfter = n - 1;
  for (int i = 1;i < n;i++) {
    if (arr[i] < arr[i - 1]) break;
    sortedUpto = i;
  }
  for (int i = n - 2;i >= 0;i--) {
    if (arr[i] > arr[i + 1])break;
    sortedAfter = i;
  }
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (good(mid))r = mid;
    else l = mid + 1;
  }
  return l;
}
};