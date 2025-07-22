class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       long long sum = 0;
       int i = 0;
       set<int>se;
       int ans = 0;
       for(int j = 0;j < nums.size();j++){
        while(se.count(nums[j])){
            se.erase(nums[i]);
            sum -= nums[i];
            i++;
        }
        sum += nums[j];
        ans = max(1ll * ans, sum);
        se.insert(nums[j]);
       } 
        return ans;
    }
};