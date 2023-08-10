class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //brute
        for(auto &&i:nums){
            if(i == target) return true;
        }
        return false;
    }
};