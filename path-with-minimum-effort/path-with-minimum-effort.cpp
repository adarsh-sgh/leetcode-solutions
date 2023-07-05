class Solution {
public:
    
#define dbg(...) 42;
int inf = 1e6;
int minimumEffortPath(vector<vector<int>>& heights) {
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>q;
  q.push({ 0,0,0 });
  int m = heights.size();
  int n = heights[0].size();
  vector<vector<int>>dis(m, vector<int>(n, inf));
  dis[0][0] = 0;
  // for (int i = 0;i < m * n - 1;i++) 
  while(!q.empty())
  {
    auto t = q.top();
    auto d = t[0], x = t[1], y = t[2];
    q.pop();

    if(d!=dis[x][y])continue;
    dbg(t);
    vector<int>dir = { -1,0,1,0,-1 };
    for (int di = 0;di < 4;di++) {
      int xn = x + dir[di], yn = y + dir[di + 1];
      if (xn < 0 || xn >= m || yn < 0 || yn >= n)continue;
      int dn =  max(d,abs(heights[xn][yn] - heights[x][y]));
      if (dis[xn][yn] > dn) {
        q.push({ dn,xn,yn });
        dis[xn][yn] = dn;
      }
    }
  }
  dbg(dis);
  return dis[m - 1][n - 1];
}
};