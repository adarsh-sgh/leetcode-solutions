class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>ans = vector<vector<int>>(m,vector<int>(n));
        for(int i = 0;i<n;i++){
            for(int j = 0;j < m; j++){
                ans[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};