class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int ans = 0;
       for(int i = 1;i< weight.size();){
        if(weight[i] < weight[i-1]){
            ans++;
            i+=2;
        }else{
            i++;
        }
       } 
       return ans;
    }
};
// last elem of subarray is not the maximum