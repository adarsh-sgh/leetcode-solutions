class Solution {
public:
// from old submission
    long long getDescentPeriods(vector<int>& prices) {
        int j = 0;
        long long ans = 1;
        for(int i = 1;i<prices.size();i++){
            if(prices[i]!=prices[i-1]-1){
                j = i;
            }
            ans += i-j+1;
        }
        return ans;
    }
};