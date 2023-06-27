class Solution {
public:
    int mod = 1e9+7;
    int countOrders(int n) {
        long long ans = 1;
        int p = n;
        for(int i = 1;i<= 2 * n;i++){
            int ic = i;
            while((~ic&1) && p > 0 ){
                ic/= 2;
                p--;
            }
            ans *= ic;
            while((~ans&1) && p > 0 ){
                ans/= 2;
                p--;
            }
            ans %= mod;
        }
        return ans;

    }
};