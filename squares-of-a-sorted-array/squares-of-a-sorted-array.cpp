class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
       vector<int>ans(n);
       int i = 0,j=0;
       while(i<n && nums[i]<0)i++;
       j = i-1;
       for(int x = 0;x<n;x++){
           if(i < n && (j < 0 ||abs(nums[i])<abs(nums[j]))){
               ans[x] = nums[i] * nums[i];
               i++;
           }else{
               ans[x] = nums[j] * nums[j];
               j--;
            }
       }
       return ans;
    }
};