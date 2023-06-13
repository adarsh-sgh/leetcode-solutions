class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int>minAfter(n+1);
        minAfter[n] = 1e6;
        for(int i = n-1;i>=0;i--){
            minAfter[i] = min(minAfter[i+1],nums[i]);
        }
        int mxBef = nums[0];
        for(int i = 1;i<n;i++){
            if(mxBef <= minAfter[i])return i;
            mxBef = max(mxBef,nums[i]);
        }
        return -1;


    }
};