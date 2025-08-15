class Solution {
public:
    vector<vector<int>>dp;
    vector<int>v;
    int mc(int i, int j){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i;k <= j;k++){
           // finish k at last
        //    int vi1 = i-1 > 0 ? v[i-1] : 1;
        //    vj1 = j+1 < v.size() ? v[j+1] : 1;
            // cerr<<i-1<<' '<<j+1<<' '<<v.size()<<endl;
            dp[i][j] = max(dp[i][j], v[i-1] * v[j+1] * v[k] + mc(i, k-1) + mc(k+1, j)); 
        }
        return dp[i][j];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
       int n = nums.size();
       dp.resize(n, vector<int>(n, -1));
       v = nums;
       return mc(1, n-2);
    }
};