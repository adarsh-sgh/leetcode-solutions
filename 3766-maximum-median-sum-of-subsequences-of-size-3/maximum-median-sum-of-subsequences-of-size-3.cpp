class Solution {
public:

    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int n = nums.size()/3;
        for(int i = n;i < 3 * n;i+=2){
            sum += nums[i];
        }
        return sum;
    }

};