class Solution {
public:
    int minMoves(vector<int>& nums) {
       // effectively one move can decrement any value 
       int minel = *min_element(nums.begin(), nums.end());
       int ans = 0;
       for(auto &x:nums){
        ans += x - minel;
       }
       return ans;
    }
};