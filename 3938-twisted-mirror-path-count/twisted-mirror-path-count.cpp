class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        long long n = grid.size(), m = grid[0].size();
        int mod = 1e9 + 7;
        // each cell stores wl, wu -> ways to reach from left, up
        vector<vector<array<long long,2>>>v(n, vector<array<long long,2>>(m));
        auto oob = [&](long long i, long long j){
            return i < 0 || j < 0 || i >= n || j >= m;
        };
        v[0][0][0] = 1;
        for(long long i = 0; i < n;i++){
            for(long long j = 0; j < m;j++){
                if(i + j == 0) continue;
                if(!oob(i-1,j))v[i][j][0] =  v[i-1][j][1] + v[i-1][j][0] * (1 - grid[i - 1][j]) ;
                if(!oob(i,j-1))v[i][j][1] =  v[i][j-1][0] + v[i][j - 1][1] * (1 - grid[i][j - 1]);
                v[i][j][0] %= mod;
                v[i][j][1] %= mod;
            }
        }
        return (v[n-1][m-1][0] + v[n-1][m-1][1]) % mod;
    }
};


/// mirrors are  like \ in a right cell
/// and like \ in a 