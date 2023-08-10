class Solution {
public:

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
      unordered_map<int,vector<int>>m;
      int mkey = -1;
      for(int i = nums.size()-1;i >= 0;i--){
          for(int j = 0;j<nums[i].size();j++){
              m[i+j].push_back(nums[i][j]);
              mkey = max(mkey,i+j);
          }
      }  
      vector<int>ans;
      for(int k = 0;k<=mkey;k++){
          auto &x = m[k];
          for(auto &&y:x){
              ans.push_back(y);
          }
      }
      return ans;
    }

};