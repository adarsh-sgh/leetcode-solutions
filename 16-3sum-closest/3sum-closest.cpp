class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        // sum - target
        int minDiff = 1e9;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j < nums.size();j++){
                int t = target - nums[i] - nums[j];
                auto it = upper_bound(nums.begin() + j + 1,nums.end(),t);
                if(it != nums.end()){
                    if(abs(*it - t) < abs(minDiff)) minDiff = *it - t;
                }
                if(it - nums.begin() == j+1)continue;
                it--;
                // cout<<*it<<' '<<t<<' '<<minDiff;
                if(abs(*it - t) < abs(minDiff)) minDiff = *it - t;
            }
        }
        return target + minDiff;
    }
};