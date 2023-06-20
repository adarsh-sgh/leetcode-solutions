class Solution {
public:
    #define ll long long
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        ll ans = 0;
        for(int i = 1;i<=n;i++){
            ll curr = 0;
            int k = 1;
            for(int j = n-i;j<n;j++){
                curr += k * v[j];
                k++;
            }
            ans = max(curr,ans);
        }
        return ans;
    }
};