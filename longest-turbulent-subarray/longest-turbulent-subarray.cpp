class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>>dp(n,pair<int,int>{1,1});
        int ans = 1;
        for(int i = 1;i<n;i++){
            if(arr[i]==arr[i-1])continue;
            if(arr[i] < arr[i-1]){
                dp[i].second =dp[i-1].first + 1;
                ans = max(ans,dp[i].second);
            }else{
                dp[i].first = dp[i-1].second + 1;
                ans = max(ans,dp[i].first);
            }
        }
        return ans;
    }
};