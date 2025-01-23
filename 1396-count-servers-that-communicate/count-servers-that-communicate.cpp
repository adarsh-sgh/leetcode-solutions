class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>v1(n), v2(m);
        int ans = 0;
        for(int i = 0;i< n;i++){
            for(int j = 0;j<m;j++){
                // grid[i][0]++;
                if(!grid[i][j])continue;
                v1[i]++;
                v2[j]++;
                // grid[0][j]++;
            }
        }        
        for(int i = 0;i< n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] && (v1[i] > 1 || v2[j] > 1))ans++;
            }
        }
        return ans;
    }
};

// 1 0 
// 1 1 

