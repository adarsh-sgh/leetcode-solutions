class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
       queue<array<int,2>>q;
       int n = isWater.size(), m = isWater[0].size();
       vector<vector<int>>dis(n,vector<int>(m, 1e8));
       for(int i = 0;i < n;i++){
            for(int j = 0;j<m;j++){
                if(!isWater[i][j])continue;
                q.push({i,j});
                dis[i][j] = 0;
            }
       } 
       auto oob = [&](int x, int y){
        return x < 0 || y < 0 || x >= n || y >= m;
       };
       vector<int> dir = {-1,0,1,0,-1};
       int ans = 0;
       while(q.size()){
        auto t = q.front();
        q.pop();
        int x = t[0], y = t[1];
        for(int d = 0; d< 4;d++){
            int xn = x + dir[d], yn = y + dir[d+1];
            if(oob(xn, yn)) continue;
            if(dis[xn][yn] <= dis[x][y] + 1) continue;
            dis[xn][yn] = dis[x][y] + 1;
            ans = max(ans, dis[xn][yn]);
            q.push({xn,yn});
        }
       }
       return dis;
    }
};