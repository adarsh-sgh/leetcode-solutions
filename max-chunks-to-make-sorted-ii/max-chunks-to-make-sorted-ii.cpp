class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
  int n = arr.size();
  vector<int>maxBef(n + 1, INT_MIN), minAf(n + 1, INT_MAX);
  for (int i = 0;i < n;i++) {
    maxBef[i + 1] = max(maxBef[i], arr[i]);
  }
  for (int i = n - 1;i >= 0;i--) {
    minAf[i] = min(minAf[i + 1], arr[i]);
  }
  int ans = 0;
  for (int i = 0;i<n;i++){
    if(maxBef[i]<= minAf[i])ans++;
  }
  return ans;
}
};