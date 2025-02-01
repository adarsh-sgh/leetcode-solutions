class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        // give an id to each island
        // store id, size for each island in a map
        // for every 0 sum the size of all id's on it's 4 directions
        vector<int>dir = {-1, 0 , 1 , 0, -1};
        int ID = 2;
        int n = grid.size(), m = grid[0].size();
        map<int,int>mp;
          auto oob = [&](int i, int j){
            return i < 0 || j < 0 || i >= n || j >= m;
        };
        function<void(int,int)> dfs = [&](int i, int j)->void{
            if(oob(i,j) || grid[i][j] != 1) return;
            grid[i][j] = ID;
            mp[ID]++;
            for(int d = 0;d<4;d++){
                dfs(i + dir[d], j + dir[d+1]);
            }
        };
      
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j< m;j++){
                if(grid[i][j] != 1) continue;
                dfs(i,j);
                ans = max(ans,mp[ID]);
                ID++;
            }
        }
        for(int i = 0;i< n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] != 0)continue;
                set<int>nbr;
                for(int d = 0;d < 4;d++){
                    int in = i + dir[d], jn = j + dir[d+1];
                    if(oob(in,jn))continue;
                    nbr.insert(grid[in][jn]);
                }
                int sum = 0;
                for(auto &x:nbr){
                    sum += mp[x];
                }
                ans = max(ans, 1 + sum);
            }
        }
        return ans;

    }
};