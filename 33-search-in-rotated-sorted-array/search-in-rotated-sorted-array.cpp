class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r){
            if(nums[0] < nums.back())break;
            int mid = (l + r)/2;
            if(nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }

        if(target <= nums.back()){
            r = n -1;
        }else{
            r = l -1;
            l = 0;
        }
        cout<<l<<' '<<r;
        auto in = lower_bound(nums.begin() + l, nums.begin() + r + 1,target) - nums.begin();
        if(nums[in]==target) return in;
        return -1;
    }
};