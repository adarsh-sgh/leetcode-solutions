class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // prefix sum and binary search
        int n = nums.size();
        auto good = [&](int x){
            // make all zeroes with items upto x index
           assert(x < (int)queries.size());
           vector<int>p(n+1);
           for(int i = 0;i <= x; i++){
                auto qi = queries[i];
                auto val = qi[2];
                p[qi[0]] -= val;
                p[qi[1]+1] += val;
           }
           for(int i = 0;i< n;i++){
            p[i+1] += p[i];
            if(p[i] + nums[i] > 0)return false;
           }
           return true;
        };
        int l = -1, r = queries.size() - 1;
        while(l < r){
            int m = (l+r)>>1;
            if(good(m)){
               r = m; 
            }else{
                l = m + 1;
            }
        }
        if(good(l))return l+1;
        return -1;
    }
};