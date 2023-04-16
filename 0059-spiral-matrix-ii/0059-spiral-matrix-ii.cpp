class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>m(n,vector<int>(n));
        if(n==0) return m;
        int cnt = 1;
        int i = 0,j = 0;
        vector<int> dx {0,1,0,-1};
        vector<int> dy {1,0,-1,0};
        int d = 0;
        while(cnt <= n*n) {
            m[i][j] = cnt++;
            int inew = i + dx[d];
            int jnew = j + dy[d];
            if(inew < 0||inew >= n || jnew < 0 || jnew >= n || m[inew][jnew])d++;
            d%=4;
            i+=dx[d];
            j+=dy[d];
        }
        return m;
    }
};