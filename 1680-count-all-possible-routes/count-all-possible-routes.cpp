class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int mod = 1e9+7;
        vector<vector<int>>dp(n,vector<int>(fuel+1));
        dp[start][fuel] = 1;
    for(int f = fuel -1;f>=0;f--){
        for(int l = 0;l<n;l++){
                for(int i = 0;i<n;i++){
                if(i==l)continue;
                int fli = abs(locations[l] - locations[i]);
                if(f+fli > fuel)continue;
                 dp[l][f] += dp[i][f+fli]; 
                 dp[l][f] %= mod; 
                }
            }
        }
        return accumulate(dp[finish].begin(),dp[finish].end(),0ll) % mod;
    }
};