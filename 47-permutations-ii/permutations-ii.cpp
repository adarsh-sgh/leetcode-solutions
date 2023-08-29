class Solution {
public:
    vector<vector<int>>ans;
    void pm(vector<int>nums,int index){
        if(index == nums.size() - 1){
            ans.push_back(nums);
            return;
        }
        for(int i = index;i<nums.size();i++){
            if(i != index && nums[i]==nums[index])continue;
            swap(nums[i],nums[index]);
            pm(nums,index + 1);
            // swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        pm(nums,0);
        return ans;
    }
};