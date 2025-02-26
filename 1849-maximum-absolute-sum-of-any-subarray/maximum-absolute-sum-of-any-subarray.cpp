class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       // max absolute => most negative or most positive
       int mn = 0, mx = 0;
       int ans = 0;
       for(auto &x:nums){
         mn = min(x, mn + x);
         mx = max(x, mx + x);
         ans = max({ans, abs(mn), abs(mx)});
       }
       return ans;
    }
};