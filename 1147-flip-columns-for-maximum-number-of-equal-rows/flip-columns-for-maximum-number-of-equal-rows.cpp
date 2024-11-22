class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        auto val = [&](vector<int>&xm){
            int ans = 0;
            for(auto &r:matrix){
                bool hope = 1;
               for(int i = 1;i<r.size();i++){
                if((r[i] ^ xm[i]) != (r[i-1] ^ xm[i-1])){
                    hope = 0;
                    break;
                }
               } 
               ans += hope;
            }
            return ans;
        };
        int ans = 0;
        for(auto &r:matrix){
            vector<int>xm = r;
            ans = max(ans, val(xm));
            for(auto &x:xm) x = !x;
            ans = max(ans, val(xm));
        }
        return ans;
    }
};