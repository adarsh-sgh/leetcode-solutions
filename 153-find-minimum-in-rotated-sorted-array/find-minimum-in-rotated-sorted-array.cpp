class Solution {
public:
    // 3, 4, 5, 1, 2
    // f f f t t 
    // 1, 2 -> t 
    // good => v[i] < v[0]
    // baaki sabpar false de
    bool good(vector<int>&v, int i){
       return v[i] < v[0]; 
    }

    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = (l + r) /2;
            if(good(nums, m)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        if(!good(nums, l)){
            return nums[0]; 
        }
        return nums[l];
    }
};

// 4,5,6,7,0,1,2
// 0 1 2 4 5 6 7