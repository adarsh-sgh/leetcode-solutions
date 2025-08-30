class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n - 2;
        if(n==1) return 0;
        if(nums[0] > nums[1])return 0;
        if(nums.back() > nums[n-2]) return n - 1;
        while(l < r){
            int m = (l + r)/2;
            if(nums[m] < nums[m+1]){
                l = m + 1;
            }else if(nums[m] < nums[m-1]){
                r = m - 1;
            }else{
                return m;
            }
        }
        return l;
    }
};