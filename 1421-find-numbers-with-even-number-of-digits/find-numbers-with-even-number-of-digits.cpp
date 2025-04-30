class Solution {
public:
    int digs(int x){
        int ans = 0;
        while(x){
            x/=10;
            ans++;
        }
        return ans;
    }
    int findNumbers(vector<int>& nums) {
       int ans = 0;
       for(auto &x:nums){
        ans += digs(x) %2 == 0;
       }
       return ans;
    }
};