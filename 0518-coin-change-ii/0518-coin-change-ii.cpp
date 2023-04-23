class Solution {
public:
    vector<vector<int>>dp;
    vector<int>c;
    int ways(int amount,int ind){
        if(amount==0) return 1;
        if(ind >= c.size()) return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int wy = 0;
        for(int val = 0;val <= amount;val+=c[ind]){
            wy += ways(amount-val,ind+1);
        }
        
        return dp[ind][amount]=wy;
    }
    int change(int amount, vector<int>& coins) {
        c = coins;
        dp.resize(301,vector<int>(5001,0));

        // return ways(amount,0);
        for(int am = 0;am<=amount;am++){
            dp[0][am] = am % coins[0] == 0;
        }
        for(int i = 1;i<coins.size();i++){
            for(int am = 0;am<=amount;am++)
                for(int value = 0;value<=amount;value+=coins[i]){
                    if(am-value>=0)dp[i][am] += dp[i-1][am-value];
            }
        }
        return dp[coins.size()-1][amount];
    }
};