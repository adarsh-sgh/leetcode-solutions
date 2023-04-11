class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        unsigned long long bm = 1<<n;
        vector<vector<int>>ans;
        for(int i = 0;i<bm;i++){
          ans.push_back({});
          for(int j = 0;j<nums.size();j++){
            if(i & (1<<j)){
              ans.back().push_back(nums[j]);
              //include jth element;
            }
          }
        }
        return ans;
    }
};