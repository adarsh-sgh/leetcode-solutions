class Solution {
public:
// iske pahle 
// window i to j, curr at j 
// minKi, maxKi, minKChotaI, maxKBadaI
// i <= min(minKi, maxKi)
//i > max(minKChotaI, maxKBadaI)
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long long ans = 0;
       int minKi = -1, maxKi = -1, minKChotaI = -1, maxKBadaI = -1; 

       for(int j = 0; j < nums.size();j++){
        if(nums[j] == minK){
            minKi = j;
        }else if(nums[j] < minK){
            minKChotaI = j;
        }

        if(nums[j] == maxK){
            maxKi = j;
        }else if(nums[j] > maxK){
            maxKBadaI = j;
        }
        int imax = min(minKi, maxKi);
        if(imax == -1) continue;
        int imin = max(minKChotaI, maxKBadaI) + 1;
        ans += max(imax - imin + 1, 0);
       }
       return ans;
    }
};