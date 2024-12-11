class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       auto good = [&](int l){
         for(int i = 0; i + l - 1<n;i++){
            if(nums[i + l -1] - nums[i] <= 2 * k) return true;
         }
         return false;
       };
       int l = 0, r = n;
       // t t t f f f 
       while(l < r){
        int m = (l + r + 1) >> 1;
        if(good(m)){
            l = m;
        }else{
           r = m - 1;
        }
       }
       return l;
    }
};