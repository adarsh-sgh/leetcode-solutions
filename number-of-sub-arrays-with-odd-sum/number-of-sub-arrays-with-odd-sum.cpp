class Solution {
public:
int mod = 1e9+7;
int numOfSubarrays(vector<int>& arr) {
  int sum = 0;
  vector<int>v{1, 0};
  int ans = 0;
  for (int i = 0;i < arr.size();i++) {
    sum ^= arr[i];
    ans += v[~sum & 1];
    ans%=mod;
    v[sum & 1]++;
  }
  return ans;
}
};