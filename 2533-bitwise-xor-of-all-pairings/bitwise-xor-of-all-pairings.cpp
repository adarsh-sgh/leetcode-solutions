class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       // num3.size = 12 
       // n2 * nums1[i] n1 * nums2[i]
       int xr = 0;
       if(nums2.size() % 2 == 1){
            for(auto &x:nums1){
             xr ^= x;
            } 
       }
       if(nums1.size() % 2 == 1){
        for(auto &x:nums2){
            xr ^= x;
        }
       }
       return xr;
    }
};