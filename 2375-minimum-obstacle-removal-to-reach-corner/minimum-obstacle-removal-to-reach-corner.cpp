class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        deque<array<int,3>>q;
        q.push_front({0,0,0});
        // 2 -> visited
        grid[0][0] = 2;
        vector<int>dir{-1,0,1,0,-1};
        while(q.size()){
            auto [x,y,dis] = q.front();
            q.pop_front();
            if(x==grid.size()-1 && y == grid[0].size()-1) return dis;
            for(int d = 0;d<4;d++){
                int xn = x + dir[d],yn = y + dir[d + 1];
                if(xn < 0 || yn < 0 || xn >= grid.size()||yn>= grid[0].size() || grid[xn][yn]==2)continue;
                // q.push({xn,yn,dis + grid[xn][yn]});
                if(grid[xn][yn]){
                    q.push_back({xn,yn,dis+1});
                }else{
                    q.push_front({xn,yn,dis});
                }
                grid[xn][yn] = 2;
            }
        }
        assert(false);
    }
};