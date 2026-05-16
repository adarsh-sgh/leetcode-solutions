class Solution {
public:
    int findMin(vector<int>& nums) {
       // binary search  but O(n) ugly complexity
       int n = nums.size();
       int l = 0, r  = n-1;
       while(l < n && nums[l]==nums[0])l++;
       // first index such that  v[i] <= v[0]
       // false false false, true, true true
       while(l < r){
        int m = (l+ r)/2;
        if(nums[m] <= nums[0]){
            r = m;
        }else{
            l = m + 1;
        }
       }
       cout<<l;
       if(l >=n || nums[0] < nums.back()) return nums[0];
       return nums[l];
    }
};