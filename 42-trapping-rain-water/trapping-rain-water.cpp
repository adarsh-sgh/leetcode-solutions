class Solution {
public:
    int trap(vector<int>& height) {
       // hl -> highest bar on left, similarly hr
       // trapped[i] = max(0, min(hl, hr) - hi)
        int n = height.size();
        vector<int>maxl(n);
        vector<int>maxr(n);
        for(int i = 1;i< n;i++){
            maxl[i] = max(maxl[i-1], height[i-1]);
        }
        for(int i = n-2;i>=0;i--){
            maxr[i] = max(maxr[i+1], height[i+1]);
        }
        int ans = 0;
        for(int i = 1;i<n-1;i++){
            // cout<<ans<<' ';
            ans += max(0, min(maxl[i], maxr[i]) - height[i]);
        }
        return ans;
    }
};