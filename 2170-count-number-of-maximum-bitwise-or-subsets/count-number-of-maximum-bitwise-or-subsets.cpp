class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
       int mor = 0;
       int ans = 0;
       for(auto &x:nums) mor |= x;
       int n = nums.size();
       for(int i = 0;i < (1<<n);i++){
            int cor = 0;
            for(int j = 0; j < n;j++){
                if(i >> j & 1){
                    cor |= nums[j];
                }
            }
            if(cor == mor) ans++;
       } 
       return ans;
    }
};