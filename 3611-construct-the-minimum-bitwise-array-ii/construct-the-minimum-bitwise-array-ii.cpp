class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // we can process each index independently
        // how can nums[i] being a prime integer help us
        // x = y | y + 1 last digit always 1 in x
        // y = x-1 
        vector<int>ans;
        for(auto &x:nums){
            if(~x & 1){
                ans.push_back(-1);
                continue;
            }
            bool only1 = true;
            int y = 0;
            for(int i = 0;i< 32;i++){   
               if(x>>i & 1){
                if(!only1){
                   // copy the bit 1
                   y |= (1<<i);
                }
                //else let the y bit be 0
               }else{
                if(only1){
                   // first time 0, set the i-1th bit as 1 on y
                   y |= (1 << (i-1));
                   only1 = false;
                }
                //else keep y as zero
               } 
            }
            ans.push_back(y-1);
        }
        return ans;
    }
};

//  101000
//  101111
// count tailing ones in x 
// say 3 tailing 111
// y = x ki bits + 100