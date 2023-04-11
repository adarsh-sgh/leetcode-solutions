class Solution {
public:
    void pm(vector<vector<int>>&ans, vector<int>&nums,int index){
      if(index >= nums.size()-1){
        ans.push_back(nums);
        return;
      }
      for(int i = index;i<nums.size();i++){
        swap(nums[i],nums[index]);
        pm(ans,nums,index+1);
        swap(nums[i],nums[index]);
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        pm(ans,nums,0);
        return ans;
    }
};