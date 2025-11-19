class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
       set<int>se(nums.begin(), nums.end());
        while(se.count(original)){
            original *= 2;
        }
        return original;
    }
};