class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>,int>s;
        for(int i = 0;i<n;i++){
           s[grid[i]]++;
        }
        int ans = 0;
        for(int j = 0;j<n;j++){
            vector<int>col;
            for(int i = 0;i<n;i++){
                col.push_back(grid[i][j]);
            }
            if(s.count(col))ans+= s[col];
        }
        return ans;
    }
};