class Solution {
public:
    // cost to go as per direction = 0
    // cost to go random = 1
    // this is zero one bfs
    int minCost(vector<vector<int>>& grid) {
        int inf = 1e7;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, inf));
        deque<array<int, 2>> dq;
        dq.push_front({0, 0});
        dis[0][0] = 0;
        // int dis = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto oob = [&](int x, int y) {
            return x < 0 || y < 0 || x >= n || y >= m;
        };

        while (dq.size()) {
            auto [x, y] = dq.front();
            if(x == n-1 && y == m-1) return dis[x][y];
            dq.pop_front();
            for (int d = 0; d < 4; d++) {
                int cost = d + 1 != grid[x][y];
                int xn = x + dir[d][0], yn = y + dir[d][1];
                if (oob(xn, yn) || dis[xn][yn] <= dis[x][y] + cost)
                    continue;
                dis[xn][yn] = dis[x][y] + cost;
                cout<<xn<<' '<<yn<<" "<<dis[xn][yn]<<'\n';
                // if (xn == n - 1 && yn == m - 1)
                    // return dis[xn][yn];
                if (cost == 0) {
                    dq.push_front({xn, yn});
                } else {
                    dq.push_back({xn, yn});
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};