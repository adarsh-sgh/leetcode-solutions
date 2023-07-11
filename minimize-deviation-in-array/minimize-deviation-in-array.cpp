class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for(auto &&x:nums){
            if(x&1) x = 2*x;
        }
        set<int>se(nums.begin(),nums.end());
        int ans = (*se.rbegin() - *se.begin());
        while(~*se.rbegin()&1){
            int x = *se.rbegin();
            x/=2;
            se.erase(--se.rbegin().base());
            se.insert(x);
            ans = min(ans,*se.rbegin() - *se.begin());
        }
        return ans;
    }
};