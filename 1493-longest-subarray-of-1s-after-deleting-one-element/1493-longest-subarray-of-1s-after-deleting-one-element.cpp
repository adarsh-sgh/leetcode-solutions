class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int z = 0;
        int n = nums.size();
        int j=0;
        for(int i =0;i<n;i++){
            z+=!nums[i];
            while(z>1){
                z-=!nums[j++]--;
            }
            ans = max(ans,i-j);
        }
        return ans;

    }
};