class Solution {
public:
    vector<bool>valid;
    
    bool validPartition(vector<int>& nu) {
        vector<long long>nums(nu.begin(),nu.end());
        int n = nums.size();
        valid.resize(n+3);
        if(nums[n-2] == nums.back()) valid[n-2] = true;
        valid[n]= valid[n+1] = valid[n+2] = true;
        for(int i= n-3;i>=0;i--){
            valid[i] = valid[i+3] && ((nums[i] == nums[i+1] && nums[i+1] == nums[i+2])||(nums[i]== nums[i+1] - 1 && nums[i+1]== nums[i+2]-1));
            valid[i] = valid[i] ||(valid[i+2] && (nums[i+1]== nums[i]));
        }
        return valid[0];
    }
};