class Solution {
public:
    int maxProfit(vector<int>& prices) {
       //6 3  7 1 
       int sabseChota = INT_MAX;
       int ans = 0;
       for(int i = 0;i < prices.size();i++){
        sabseChota  = min(sabseChota, prices[i]);
        ans = max(ans, prices[i] - sabseChota);
       }
       return ans;
    }
};