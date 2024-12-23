class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
       int makeIt = -2e9;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(auto &x:nums){
            if(makeIt > x + k)continue;
            // making makeIt is possible
            if(abs(makeIt - x) <= k){
                makeIt++;
            }else{
                makeIt = x - k + 1;
            }
            ans++;
        }
        return ans;
    }
};