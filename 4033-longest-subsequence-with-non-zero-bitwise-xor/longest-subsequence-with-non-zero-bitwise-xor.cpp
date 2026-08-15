class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       // if xor(nums) != 0, return n
       // else remove any non zero element and rest would have xor equal to that element hence non zero
       // hence return n - 1
       // if all elements are zero return 0;
       int xr = 0;
       int nz = 0;
       for(auto &x:nums){
        xr ^= x;
        if(x != 0) nz = 1;
       }
       
       if(xr) return nums.size();
       if(nz) return nums.size() - 1;
       return 0;
    }
};