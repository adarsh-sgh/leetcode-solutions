class Solution {
public:
bool canReorderDoubled(vector<int>& arr) {
  sort(arr.begin(), arr.end(), [](auto x, auto y) {
    return  abs(x) < abs(y);
    });
  int n = arr.size();
  map<int, int>mp;
  for (int i = 0;i < n;i++) {
    if ((~arr[i] & 1) && mp.count(arr[i] / 2)) {
      mp[arr[i] / 2]--;
      if (mp[arr[i] / 2] == 0) {
        mp.erase(arr[i] / 2);
      }
    }
    else {
      mp[arr[i]]++;
    }
    // dbg(mp)
  }
  return mp.size() == 0;
}
};