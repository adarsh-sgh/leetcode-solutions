class Solution {
public:
    //hats[i] = {x,y,z} -> ith hat is accepted by x,y,z
    vector<vector<int>>hats;
    //people,hat
    int N = 1<<10;
    int mod = 1e9 + 7;
    vector<vector<int>>dp;
    int ways(unsigned int p,int i){
        if(i==40)return p==0;
        int &res = dp[i][p];
        if(res != -1)return res;
         res = ways(p,i+1);
        for(auto x:hats[i]){
            if(p & (1<<x))res += ways(p^(1<<x),i+1);
            res %= mod;
        }
        return res;
    }
   
    int numberWays(vector<vector<int>>& h) {
        hats.resize(40);
        for(int i = 0;i<h.size();i++){
            for(auto x:h[i]){
                x--;
                hats[x].push_back(i);
            }
        }
        dp.resize(41,vector<int>(1<<10,-1));
        return ways((1<<h.size()) - 1,0);
    }
};