class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
      // two pointer
      int j = 0;
      int n = nums.size();
      int bm = 0;
      int ans = 0;
      for(int i = 0;i<n;i++){
        while(nums[i] & bm){
           bm ^= nums[j];
           j++; 
        }
        bm |= nums[i];
        ans = max(ans, i - j + 1);
      } 
      return ans;
    } 
};