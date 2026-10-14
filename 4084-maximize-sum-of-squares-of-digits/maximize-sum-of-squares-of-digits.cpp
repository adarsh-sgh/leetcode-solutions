class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
          string ans;
       while(num--){
        int put = min(9,sum);
        ans += to_string(put);
        sum -= put;
       }
       if(sum) return "";
       return ans;
    }
};
