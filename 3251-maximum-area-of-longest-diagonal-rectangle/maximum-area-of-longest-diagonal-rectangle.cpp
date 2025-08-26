class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       int ld = 0;
       int ans = 0;
       for(auto &x:dimensions){
            int a = x[0], b = x[1];
            if(a * a + b * b > ld){
                ld = a * a + b * b;
                ans = a * b;
            }else if(a * a + b * b == ld){
                ans = max(ans, a * b);
            }
        } 
        return ans;
    }
};