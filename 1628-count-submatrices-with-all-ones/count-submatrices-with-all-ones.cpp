class Solution {
public:
// m * n = 22500
// can't go n^4 brute force

    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 1;i < n;i++){
            for(int j = 0;j < m; j++){
                if(mat[i][j]){
                    mat[i][j] += mat[i-1][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int mn = mat[i][j];
                for(int k = j;k>=0;k--){
                    mn = min(mn, mat[i][k]);
                    ans += mn;
                }
                // cout<<i<<' '<<j<<' '<<ans<<endl;
            }
        }
        return ans;
    }
};