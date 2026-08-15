class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       // if xor(nums) != 0, return n
       // else remove any non zero element and rest would have xor equal to that element hence non zero
       // hence return n - 1
       // if all elements are zero return 0;
       int xr = 0;
       bool nz = 0;
       int n = nums.size();
       for(auto &&x:nums){
        xr ^= x;
        nz |= x;
       }

       if(xr) return n;
       return nz * (n - 1);
       return 0;
    }
};