class Solution {
public:
    long long inf = 1e10+5;
    long long maxAlternatingSum(vector<int>& nums) {
       long long maso = -inf ,mase = 0;
       for(int i = 0;i<nums.size();i++){
           long long to = mase + nums[i];
           long long te = maso - nums[i];
           maso = max(maso,to);
           mase = max(mase,te);
       } 
       return max(maso,mase);
    }
};