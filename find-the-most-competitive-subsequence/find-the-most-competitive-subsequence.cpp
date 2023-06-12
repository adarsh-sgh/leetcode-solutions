class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>mi;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            while(mi.size()&&mi.back()>nums[i]&& mi.size() + n - i > k){
                mi.pop_back();
            }
            if(mi.size() < k)mi.push_back(nums[i]);
        }
        return mi;
    }
};