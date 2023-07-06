class Solution {
public:
   
int minKBitFlips(vector<int>& nums, int k) {
  queue<int>flipUpto;
  int ans = 0;
  for (int i = 0;i < nums.size();i++) {
    if (nums[i]== ((int)flipUpto.size() & 1)) {
      flipUpto.push(i + k - 1);
      ans++;
    }
    while (flipUpto.size() && flipUpto.front() <= i)flipUpto.pop();

  }
  if(flipUpto.size())return -1;
  return ans;
}
};