class Solution {
public:
// second half    first half
// 4,5,6,7,       0,1,2
// target -> something in first half
// v[i] >= target
// f f t t f f f
// 
// f f t t t t t, target = 6
// bool inFirst = v.back() < target;
// (v[i] >= target) || (v[i] <= v.back());

// 4,5,6,7,       0,1,2
// target = 1
// v[i] >= target && v[i] <= v.back()
//    t t t t t t t

// 0 1 2 4 5 6 7, target = 4 
// f f f t t t t => 
// v[i] >= target
bool good (vector<int>&v, int i, int t){
    bool tfh = t <= v.back();
    if(tfh){
        return v[i] >= t && v[i] <= v.back();
    }else{
        return v[i] >= t || v[i] <= v.back();
    }
}
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = (l + r)/2;
            if(good(nums,m, target)){
                r = m;
            }else{
                l = m + 1;
            }
        }        
        if(nums[l] == target) return l;
        return -1;
    }
};