class Solution {
public:
    vector<vector<int>>ans;
    void pm(vector<int>&nums,int index){
        if(index == nums.size() - 1){
            ans.push_back(nums);
            return;
        }
        for(int i = index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            pm(nums,index + 1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        pm(nums,0);
        return ans;
    }
};