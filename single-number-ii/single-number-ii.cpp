class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
    for(int i =0;i<32;i++){
        // cnt of nos in which ith bit is set 
        int cnt = 0;
        for(auto &&x:nums){
                if(x & (1<<i)) cnt++;

            }
            if(cnt % 3 != 0){
                ans = ans | (1<<i);
            }
        }
            return ans;
    }

};