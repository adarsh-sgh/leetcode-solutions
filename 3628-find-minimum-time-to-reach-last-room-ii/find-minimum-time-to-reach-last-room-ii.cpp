class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) { 
        int n = moveTime.size();
        int m = moveTime[0].size();
        int inf = INT_MAX;
       vector<vector<int>>dp(n+1,vector<int>(m+1, inf));
       // time to reach, x, y
      priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
       pq.push({0,0,0});
       dp[0][0] = 0;
       vector<int>dir{-1,0,1,0,-1};
       auto oob = [&](int x, int y){
        return x < 0 || y < 0 || x >= n || y >= m;
       };
       while(pq.size()){
          auto [_x,_y,_z] = pq.top();
          int c = _x, x = _y, y = _z;
          pq.pop();
          for(int d = 0;d < 4;d++){
            int xn = x + dir[d], yn = y + dir[d+1];
            if(oob(xn,yn))continue;
            int mt = max(c, moveTime[xn][yn]) + ((xn+ yn) % 2 ? 1 : 2);
            if(dp[xn][yn] <= mt)continue;
            pq.push({mt,xn,yn});
            dp[xn][yn] = mt;
          }
       }
      //  cout<<dp;
       return dp[n-1][m-1];
}
};