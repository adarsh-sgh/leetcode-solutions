class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>minAfter(n);
        int mn = nums.back();
        for(int i = n-1;i>=0;i-- ){
            mn = min(mn, nums[i]);
            minAfter[i] = mn;
        }
        int mx = nums[0];
        for(int i = 0;i < n;i++){
            mx = max(mx, nums[i]);
            if(mx - minAfter[i] <= k) return i;
        }
        return -1;
    }
};