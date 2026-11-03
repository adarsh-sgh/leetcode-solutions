class Solution {
public:
    int minMoves(vector<int>& nums) {
       int max_el = *max_element(nums.begin(), nums.end()) ;
       int ans = 0;
       for(auto &x:nums){
        ans += max_el - x;
       }
       return ans;
    }
};