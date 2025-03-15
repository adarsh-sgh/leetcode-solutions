class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
    //    The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.  
    // binary search
    // dp => 
    // dp[i][k] => dp 
    // dp[i][k] = nums[i], dp[i-2][k-1]
    // dp[i][k] = dp[i-1][k];

    // maxRobbed(int cap)
    // nums = [2,3,5,9], cap 
    // to find max houses robbed
    // dp[i]
    // 
    int n = nums.size();
    auto good = [&](int cap){
        vector<int>dp(n+1);
        dp[1] = nums[0] <= cap;
        for(int i = 1;i <=n;i++){
            dp[i] = max(dp[i],dp[i-1]);
            if(i >= 2 && nums[i-1] <= cap){
                dp[i] = max(dp[i], 1 + dp[i-2]);
                if(dp[i] >= k) return true;
            }
        }
        return dp.back() >= k;
    };
    int l = 0, r = *max_element(nums.begin(), nums.end());
    // f f f f t t
    // for(int i = l; i < r;i++){
    //    cout<<i<<' '<<good(i)<<endl;
    // } 
    // return -1;
    while(l < r){
        int m = (l + r)/2;
        if(good(m)){
            r = m;
        }else{
            l = m + 1;
        }
    }
    return l;
    }
};