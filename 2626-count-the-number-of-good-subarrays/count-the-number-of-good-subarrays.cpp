class Solution {
public:
#define dbg(...) 42
typedef long long int;

    long long countGood(vector<int>& nums, int k) {
  map<int, int>freq;
  long long rep = 0;
  int n = nums.size();
  int i = 0, j = 0;
  long long ans = 0;
  freq[nums[0]] = 1;
  while (i < n && j < n) {
    if (rep >= k) {
      ans += n - j;
      dbg(i, j, ans);
      // if (freq[nums[i]] == 1) {
      // }
      freq[nums[i]]--;
      rep -= freq[nums[i]];
      i++;
    }
    else {

      j++;
      if(j>=n)break;
      rep += freq[nums[j]];
      freq[nums[j]]++;
    }
    dbg(i, j, rep, freq);

  }

  return ans;
}
};