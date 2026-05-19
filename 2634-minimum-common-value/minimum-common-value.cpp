class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
       set<int>se(nums1.begin(), nums1.end()) ;
       int ans = 2e9;
       for(auto &x:nums2){
        if(se.count(x)){
            ans = min(ans, x);
        }
       }
       if(ans == 2e9) return -1;
       return ans;
    }
};