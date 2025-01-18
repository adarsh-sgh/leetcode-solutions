class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
       // weighted bfs using pq
       // pick smallest dis. el. in pq
       // put all neighours in pq whose new dist < existing dis;
       int n = grid.size(), m = grid[0].size();
       auto oob = [&](int x, int y){
        return x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0;
       };
       priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>>pq;
       vector<vector<int>>dir = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1,0}
       };
       vector<vector<int>>distance(n, vector<int>(m, INT_MAX));
       distance[0][0] = 0;
       pq.push({0,0,0});
       while(pq.size()){
        auto t = pq.top();
        int dis = t[0], x = t[1], y = t[2];
        if(x == n-1 && y == m-1) return dis;
        pq.pop();
        for(int d = 0;d < 4;d++){
            int xn = x + dir[d][0], yn = y + dir[d][1];
            if(oob(xn,yn))continue;
            int dnew = dis + (d != grid[x][y] - 1);
            // if(xn == n -1 && yn == m - 1) return dnew;
            if(distance[xn][yn] <= dnew)continue;
            distance[xn][yn] = dnew;
            pq.push({dnew, xn, yn});
        }
       }
       return -1;
    }
};