class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0;
        vector<int>ans(nums.size(),-1);
        for(int i = 0;i<nums.size();i++){
            sum+= nums[i];
            int j = i - 2 *k -1;
            if(j  >= 0){ 
                sum-=nums[j];
            }
            j++;
            if(j<0)continue;
            int mid = (i + j) /2;
            ans[mid] = sum/(2*k+1);
        }
        return ans;
    }
};