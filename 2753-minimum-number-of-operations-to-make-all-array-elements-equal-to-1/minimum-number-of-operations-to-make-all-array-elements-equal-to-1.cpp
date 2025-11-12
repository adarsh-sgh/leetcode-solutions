class Solution {
public:
    int minOperations(vector<int>& nums) {
       // gcd of all != 1 => ans = -1
       // atleast n operations always needed 
       // smallest subarray with gcd = 1 (say x), then x - 1 + n - 1 operations, x + n - 2

       int n = nums.size();
       int sm = n + 1;
       for(int i = 0;i< n;i++){
        for(int j = i;j<n;j++){
            int g = nums[i];
            for(int k = i;k <=j;k++){
                g = gcd(g, nums[k]);
            }
            if(g == 1){
                sm = min(sm, j - i + 1);
            }
        }
       }
       if(sm == 1){
        int oc = 0;
        for(auto &x:nums)oc+= x == 1;
        return n - oc;
       }
       if(sm == n+1)return -1;
       return n + sm - 2;
    }
};