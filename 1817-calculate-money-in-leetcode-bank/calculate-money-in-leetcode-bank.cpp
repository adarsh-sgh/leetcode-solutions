class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int m = 1;
        while(n > 0){
            int cur = m;
            for(int i = 0;i < 7 && n > 0;i++){
               ans +=  cur;
               cur++;
                n--;
            }
            m++;
        }
        return ans;
    }
};