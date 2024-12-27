class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // store max value of value[i] + i
       int mx = 0;
       int ans = 0;
       for(int i = 0;i<values.size();i++){
        ans = max(ans, mx + values[i] - i);
        mx = max(mx, values[i] + i);
       }
       return ans;
    }
};