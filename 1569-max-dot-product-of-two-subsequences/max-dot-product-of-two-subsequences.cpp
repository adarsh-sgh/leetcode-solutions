class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2 + 1));
        for(int i = n1 - 1;i>= 0;i--){
            for(int j = n2 -1 ; j >= 0;j--){
                dp[i][j] = max({
                    dp[i+1][j],
                    dp[i][j+1],
                    nums1[i] * nums2[j] + dp[i+1][j+1]
                });
            }
        }
        if(dp[0][0] == 0){
            // all + in one and all - in other
            if(nums1[0] > 0){
                swap(nums1,nums2);
            }
            int e1 = *max_element(nums1.begin(),nums1.end());
            int e2 = *min_element(nums2.begin(),nums2.end());
            return e1 * e2;
        }
        return dp[0][0];
    }
};