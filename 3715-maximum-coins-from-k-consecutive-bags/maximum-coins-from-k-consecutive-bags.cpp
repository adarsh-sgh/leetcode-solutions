class Solution {
public:
   #define dbg(...) 42;
   long long mc(vector<vector<int>>& coins, int k) {
       // the window will either start with start of coins[i] 
       // or end at end of coins[i]
       int n = coins.size();
       vector<long long>pref(n+1);
       for(int i = 0;i< n;i++){
        pref[i+1] = pref[i] + (coins[i][1] - coins[i][0] + 1)* 1ll * coins[i][2];
       }
       int INF = 1e9;
        long long ans = 0;
       for(int i = 0;i< coins.size();i++){
        // start window from coins[i][0]
        int l = coins[i][0], r = coins[i][0] + k - 1;
        // ir -> first range that begins after r
        // => ir - 1 begins before r, might end before it or after it 
        int ir = upper_bound(coins.begin(), coins.end(), vector<int>{r, INF,INF}) - coins.begin();
        if(!ir){dbg(i,r, ir,coins);}
        ir--;
        // sum(i, ir - 1) + partial contri from ir 
        // assert(ir >= i);
        long long res = ir >= i ? pref[ir] - pref[i] : 0;
        // coins[ir][]
        assert(ir>=0);

        int lx = coins[ir][0], rx = min(coins[ir][1], r);
        if(lx <= rx){
            res += 1ll * (rx - lx + 1) * coins[ir][2];
        }
        ans = max(ans, res);
        dbg(res, coins[i]);
       } 
       return ans;
    }

    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        long long res = mc(coins,k);
        dbg(coins);
        for(auto &x:coins){
            swap(x[0],x[1]);
            x[0] *= -1;
            x[1] *= -1;
        }
        sort(coins.begin(), coins.end());
        res = max(res, mc(coins,k));
        return res;
    }
};