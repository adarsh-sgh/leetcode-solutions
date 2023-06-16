class Solution {
public:
int waysToMakeFair(vector<int>& nums) {
  int n = nums.size();
  vector<int>suffEven(n + 1), suffOdd(n + 1);
  for (int i = n - 1;i >= 0;i--) {
    suffEven[i] = suffEven[i + 1];
    suffOdd[i] = suffOdd[i + 1];
    if (i & 1) {
      suffOdd[i] += nums[i];
    }
    else {
      suffEven[i] += nums[i];
    }
  }
  int cnt = 0;
  for (int i = 0;i < n;i++) {
    int inr = nums[i];
    if (~i & 1) inr = -inr;
    inr += 2 * (-suffEven[i + 1] + suffOdd[i + 1]);
    if (suffEven[0] + inr == suffOdd[0]) {
      cnt++;
    }
  }
  return cnt;
}
};