class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
       for(int i = 0;i< n-2; ){
            int j = i + 1, k = n - 1;
            int t = -nums[i];
            while(j < k){
                if(nums[j] + nums[k] < t)j++;
                else if(nums[j] + nums[k] > t)k--;
                else {
                ans.push_back({nums[i], nums[j], nums[k]});
                while(j<n-1&&nums[j] == nums[j+1])j++;
                j++;
                // break;
                }
            }
            
            while(i < n - 1 && nums[i+1] == nums[i])i++;
            i++;
       } 
       return ans;
    }
};