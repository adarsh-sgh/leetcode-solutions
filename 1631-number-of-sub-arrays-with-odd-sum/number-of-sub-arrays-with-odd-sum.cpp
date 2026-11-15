class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int os = 0, es = 1;
        int sum = 0;
        int ans = 0;
        int m = 1e9 + 7;
        for(auto &x:arr){
            sum += x;
            if(sum &1 ){
                ans += es;
                os++;
            }else{
                ans += os;
                es++;
            }
            es %= m;
            os %= m;
            ans %= m;
        }
        return ans;
    }
};